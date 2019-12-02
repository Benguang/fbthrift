/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <folly/Portability.h>
#if FOLLY_HAS_COROUTINES
#include <folly/experimental/coro/AsyncGenerator.h>
#endif // FOLLY_HAS_COROUTINES
#include <folly/Try.h>
#include <thrift/lib/cpp2/async/ServerGeneratorStream.h>
#include <thrift/lib/cpp2/async/ServerPublisherStream.h>
#include <thrift/lib/cpp2/async/StreamCallbacks.h>

namespace apache {
namespace thrift {

template <typename T>
class ServerStream {
 public:
#if FOLLY_HAS_COROUTINES
  /* implicit */ ServerStream(folly::coro::AsyncGenerator<T&&>&& gen)
      : fn_(detail::ServerGeneratorStream::fromAsyncGenerator(std::move(gen))) {
  }
#endif

  /* implicit */ ServerStream(Stream<T>&& stream)
      : fn_([stream = std::move(stream)](
                folly::Executor::KeepAlive<>,
                folly::Try<StreamPayload> (*encode)(folly::Try<T>&&)) mutable {
          return [stream = std::move(stream).map(
                      [encode](T&& item) mutable {
                        return encode(folly::Try<T>(std::forward<T>(item)))
                            .value()
                            .payload;
                      },
                      [encode](folly::exception_wrapper&& ew) mutable {
                        return encode(folly::Try<T>(std::move(ew))).exception();
                      })](
                     FirstResponsePayload&& payload,
                     StreamClientCallback* callback,
                     folly::EventBase* clientEb) mutable {
            auto streamPtr =
                std::move(stream).toStreamServerCallbackPtr(*clientEb);
            streamPtr->resetClientCallback(*callback);
            callback->onFirstResponse(std::move(payload), clientEb, streamPtr);
          };
        }) {}

  static std::pair<ServerStream<T>, ServerStreamPublisher<T>> createPublisher(
      folly::Function<void()> onStreamCompleteOrCancel) {
    auto pair = detail::ServerPublisherStream<T>::create(
        std::move(onStreamCompleteOrCancel));
    return std::make_pair<ServerStream<T>, ServerStreamPublisher<T>>(
        ServerStream<T>(std::move(pair.first)), std::move(pair.second));
  }

  detail::ServerStreamFactory operator()(
      folly::Executor::KeepAlive<> serverExecutor,
      folly::Try<StreamPayload> (*encode)(folly::Try<T>&&)) {
    return fn_(std::move(serverExecutor), encode);
  }

  // convenience operator for tests

  void operator()(
      FirstResponsePayload&& payload,
      StreamClientCallback* callback,
      folly::EventBase* clientEb,
      folly::Executor::KeepAlive<> serverExecutor,
      folly::Try<StreamPayload> (*encode)(folly::Try<T>&&)) {
    fn_(std::move(serverExecutor), encode)(
        std::move(payload), callback, clientEb);
  }

 private:
  explicit ServerStream(detail::ServerStreamFn<T> fn) : fn_(std::move(fn)) {}

  detail::ServerStreamFn<T> fn_;
};

template <typename Response, typename StreamElement>
struct ResponseAndServerStream {
  using ResponseType = Response;
  using StreamElementType = StreamElement;

  Response response;
  ServerStream<StreamElement> stream;
};
struct ResponseAndServerStreamFactory {
  folly::IOBufQueue response;
  detail::ServerStreamFactory stream;
};

} // namespace thrift
} // namespace apache
