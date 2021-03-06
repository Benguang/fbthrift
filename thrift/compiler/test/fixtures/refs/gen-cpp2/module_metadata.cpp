/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include <thrift/lib/cpp2/gen/module_metadata_cpp.h>
#include "thrift/compiler/test/fixtures/refs/gen-cpp2/module_metadata.h"

namespace apache {
namespace thrift {
namespace detail {
namespace md {
using ThriftMetadata = ::apache::thrift::metadata::ThriftMetadata;
using ThriftPrimitiveType = ::apache::thrift::metadata::ThriftPrimitiveType;
using ThriftType = ::apache::thrift::metadata::ThriftType;
using ThriftService = ::apache::thrift::metadata::ThriftService;
using ThriftServiceContext = ::apache::thrift::metadata::ThriftServiceContext;
using ThriftFunctionGenerator = void (*)(ThriftMetadata&, ThriftService&);

void EnumMetadata<::cpp2::TypedEnum>::gen(ThriftMetadata& metadata) {
  auto res = metadata.enums.emplace("module.TypedEnum", ::apache::thrift::metadata::ThriftEnum{});
  if (!res.second) {
    return;
  }
  ::apache::thrift::metadata::ThriftEnum& enum_metadata = res.first->second;
  enum_metadata.name = "module.TypedEnum";
  for (const auto& p : ::cpp2::_TypedEnum_VALUES_TO_NAMES) {
    enum_metadata.elements.emplace(static_cast<int32_t>(p.first), p.second) ;
  }
}

void StructMetadata<::cpp2::MyUnion>::gen(ThriftMetadata& metadata) {
  auto res = metadata.structs.emplace("module.MyUnion", ::apache::thrift::metadata::ThriftStruct{});
  if (!res.second) {
    return;
  }
  ::apache::thrift::metadata::ThriftStruct& module_MyUnion = res.first->second;
  module_MyUnion.name = "module.MyUnion";
  module_MyUnion.is_union = true;
  static const std::tuple<int32_t, const char*, bool, std::unique_ptr<MetadataTypeInterface>>
  module_MyUnion_fields[] = {
    std::make_tuple(1, "anInteger", false, std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_I32_TYPE)),
    std::make_tuple(2, "aString", false, std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_STRING_TYPE)),
  };
  for (const auto& f : module_MyUnion_fields) {
    ::apache::thrift::metadata::ThriftField field;
    field.id = std::get<0>(f);
    field.name = std::get<1>(f);
    field.is_optional = std::get<2>(f);
    std::get<3>(f)->writeAndGenType(field.type, metadata);
    module_MyUnion.fields.push_back(std::move(field));
  }
}
void StructMetadata<::cpp2::MyField>::gen(ThriftMetadata& metadata) {
  auto res = metadata.structs.emplace("module.MyField", ::apache::thrift::metadata::ThriftStruct{});
  if (!res.second) {
    return;
  }
  ::apache::thrift::metadata::ThriftStruct& module_MyField = res.first->second;
  module_MyField.name = "module.MyField";
  module_MyField.is_union = false;
  static const std::tuple<int32_t, const char*, bool, std::unique_ptr<MetadataTypeInterface>>
  module_MyField_fields[] = {
    std::make_tuple(1, "opt_value", true, std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_I64_TYPE)),
    std::make_tuple(2, "value", false, std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_I64_TYPE)),
    std::make_tuple(3, "req_value", false, std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_I64_TYPE)),
  };
  for (const auto& f : module_MyField_fields) {
    ::apache::thrift::metadata::ThriftField field;
    field.id = std::get<0>(f);
    field.name = std::get<1>(f);
    field.is_optional = std::get<2>(f);
    std::get<3>(f)->writeAndGenType(field.type, metadata);
    module_MyField.fields.push_back(std::move(field));
  }
}
void StructMetadata<::cpp2::MyStruct>::gen(ThriftMetadata& metadata) {
  auto res = metadata.structs.emplace("module.MyStruct", ::apache::thrift::metadata::ThriftStruct{});
  if (!res.second) {
    return;
  }
  ::apache::thrift::metadata::ThriftStruct& module_MyStruct = res.first->second;
  module_MyStruct.name = "module.MyStruct";
  module_MyStruct.is_union = false;
  static const std::tuple<int32_t, const char*, bool, std::unique_ptr<MetadataTypeInterface>>
  module_MyStruct_fields[] = {
    std::make_tuple(1, "opt_ref", true, std::make_unique<Struct< ::cpp2::MyField>>("module.MyField")),
    std::make_tuple(2, "ref", false, std::make_unique<Struct< ::cpp2::MyField>>("module.MyField")),
    std::make_tuple(3, "req_ref", false, std::make_unique<Struct< ::cpp2::MyField>>("module.MyField")),
  };
  for (const auto& f : module_MyStruct_fields) {
    ::apache::thrift::metadata::ThriftField field;
    field.id = std::get<0>(f);
    field.name = std::get<1>(f);
    field.is_optional = std::get<2>(f);
    std::get<3>(f)->writeAndGenType(field.type, metadata);
    module_MyStruct.fields.push_back(std::move(field));
  }
}
void StructMetadata<::cpp2::StructWithUnion>::gen(ThriftMetadata& metadata) {
  auto res = metadata.structs.emplace("module.StructWithUnion", ::apache::thrift::metadata::ThriftStruct{});
  if (!res.second) {
    return;
  }
  ::apache::thrift::metadata::ThriftStruct& module_StructWithUnion = res.first->second;
  module_StructWithUnion.name = "module.StructWithUnion";
  module_StructWithUnion.is_union = false;
  static const std::tuple<int32_t, const char*, bool, std::unique_ptr<MetadataTypeInterface>>
  module_StructWithUnion_fields[] = {
    std::make_tuple(1, "u", false, std::make_unique<Union< ::cpp2::MyUnion>>("module.MyUnion")),
    std::make_tuple(2, "aDouble", false, std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_DOUBLE_TYPE)),
    std::make_tuple(3, "f", false, std::make_unique<Struct< ::cpp2::MyField>>("module.MyField")),
  };
  for (const auto& f : module_StructWithUnion_fields) {
    ::apache::thrift::metadata::ThriftField field;
    field.id = std::get<0>(f);
    field.name = std::get<1>(f);
    field.is_optional = std::get<2>(f);
    std::get<3>(f)->writeAndGenType(field.type, metadata);
    module_StructWithUnion.fields.push_back(std::move(field));
  }
}
void StructMetadata<::cpp2::RecursiveStruct>::gen(ThriftMetadata& metadata) {
  auto res = metadata.structs.emplace("module.RecursiveStruct", ::apache::thrift::metadata::ThriftStruct{});
  if (!res.second) {
    return;
  }
  ::apache::thrift::metadata::ThriftStruct& module_RecursiveStruct = res.first->second;
  module_RecursiveStruct.name = "module.RecursiveStruct";
  module_RecursiveStruct.is_union = false;
  static const std::tuple<int32_t, const char*, bool, std::unique_ptr<MetadataTypeInterface>>
  module_RecursiveStruct_fields[] = {
    std::make_tuple(1, "mes", true, std::make_unique<List>(std::make_unique<Typedef>("module.RecursiveStruct", std::make_unique<Struct< ::cpp2::RecursiveStruct>>("module.RecursiveStruct")))),
  };
  for (const auto& f : module_RecursiveStruct_fields) {
    ::apache::thrift::metadata::ThriftField field;
    field.id = std::get<0>(f);
    field.name = std::get<1>(f);
    field.is_optional = std::get<2>(f);
    std::get<3>(f)->writeAndGenType(field.type, metadata);
    module_RecursiveStruct.fields.push_back(std::move(field));
  }
}
void StructMetadata<::cpp2::StructWithContainers>::gen(ThriftMetadata& metadata) {
  auto res = metadata.structs.emplace("module.StructWithContainers", ::apache::thrift::metadata::ThriftStruct{});
  if (!res.second) {
    return;
  }
  ::apache::thrift::metadata::ThriftStruct& module_StructWithContainers = res.first->second;
  module_StructWithContainers.name = "module.StructWithContainers";
  module_StructWithContainers.is_union = false;
  static const std::tuple<int32_t, const char*, bool, std::unique_ptr<MetadataTypeInterface>>
  module_StructWithContainers_fields[] = {
    std::make_tuple(1, "list_ref", false, std::make_unique<List>(std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_I32_TYPE))),
    std::make_tuple(2, "set_ref", false, std::make_unique<Set>(std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_I32_TYPE))),
    std::make_tuple(3, "map_ref", false, std::make_unique<Map>(std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_I32_TYPE), std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_I32_TYPE))),
    std::make_tuple(4, "list_ref_unique", false, std::make_unique<List>(std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_I32_TYPE))),
    std::make_tuple(5, "set_ref_shared", false, std::make_unique<Set>(std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_I32_TYPE))),
    std::make_tuple(6, "list_ref_shared_const", false, std::make_unique<List>(std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_I32_TYPE))),
  };
  for (const auto& f : module_StructWithContainers_fields) {
    ::apache::thrift::metadata::ThriftField field;
    field.id = std::get<0>(f);
    field.name = std::get<1>(f);
    field.is_optional = std::get<2>(f);
    std::get<3>(f)->writeAndGenType(field.type, metadata);
    module_StructWithContainers.fields.push_back(std::move(field));
  }
}
void StructMetadata<::cpp2::StructWithSharedConst>::gen(ThriftMetadata& metadata) {
  auto res = metadata.structs.emplace("module.StructWithSharedConst", ::apache::thrift::metadata::ThriftStruct{});
  if (!res.second) {
    return;
  }
  ::apache::thrift::metadata::ThriftStruct& module_StructWithSharedConst = res.first->second;
  module_StructWithSharedConst.name = "module.StructWithSharedConst";
  module_StructWithSharedConst.is_union = false;
  static const std::tuple<int32_t, const char*, bool, std::unique_ptr<MetadataTypeInterface>>
  module_StructWithSharedConst_fields[] = {
    std::make_tuple(1, "opt_shared_const", true, std::make_unique<Struct< ::cpp2::MyField>>("module.MyField")),
    std::make_tuple(2, "shared_const", false, std::make_unique<Struct< ::cpp2::MyField>>("module.MyField")),
    std::make_tuple(3, "req_shared_const", false, std::make_unique<Struct< ::cpp2::MyField>>("module.MyField")),
  };
  for (const auto& f : module_StructWithSharedConst_fields) {
    ::apache::thrift::metadata::ThriftField field;
    field.id = std::get<0>(f);
    field.name = std::get<1>(f);
    field.is_optional = std::get<2>(f);
    std::get<3>(f)->writeAndGenType(field.type, metadata);
    module_StructWithSharedConst.fields.push_back(std::move(field));
  }
}
void StructMetadata<::cpp2::Empty>::gen(ThriftMetadata& metadata) {
  auto res = metadata.structs.emplace("module.Empty", ::apache::thrift::metadata::ThriftStruct{});
  if (!res.second) {
    return;
  }
  ::apache::thrift::metadata::ThriftStruct& module_Empty = res.first->second;
  module_Empty.name = "module.Empty";
  module_Empty.is_union = false;
}
void StructMetadata<::cpp2::StructWithRef>::gen(ThriftMetadata& metadata) {
  auto res = metadata.structs.emplace("module.StructWithRef", ::apache::thrift::metadata::ThriftStruct{});
  if (!res.second) {
    return;
  }
  ::apache::thrift::metadata::ThriftStruct& module_StructWithRef = res.first->second;
  module_StructWithRef.name = "module.StructWithRef";
  module_StructWithRef.is_union = false;
  static const std::tuple<int32_t, const char*, bool, std::unique_ptr<MetadataTypeInterface>>
  module_StructWithRef_fields[] = {
    std::make_tuple(1, "def_field", false, std::make_unique<Struct< ::cpp2::Empty>>("module.Empty")),
    std::make_tuple(2, "opt_field", true, std::make_unique<Struct< ::cpp2::Empty>>("module.Empty")),
    std::make_tuple(3, "req_field", false, std::make_unique<Struct< ::cpp2::Empty>>("module.Empty")),
  };
  for (const auto& f : module_StructWithRef_fields) {
    ::apache::thrift::metadata::ThriftField field;
    field.id = std::get<0>(f);
    field.name = std::get<1>(f);
    field.is_optional = std::get<2>(f);
    std::get<3>(f)->writeAndGenType(field.type, metadata);
    module_StructWithRef.fields.push_back(std::move(field));
  }
}
void StructMetadata<::cpp2::StructWithRefTypeUnique>::gen(ThriftMetadata& metadata) {
  auto res = metadata.structs.emplace("module.StructWithRefTypeUnique", ::apache::thrift::metadata::ThriftStruct{});
  if (!res.second) {
    return;
  }
  ::apache::thrift::metadata::ThriftStruct& module_StructWithRefTypeUnique = res.first->second;
  module_StructWithRefTypeUnique.name = "module.StructWithRefTypeUnique";
  module_StructWithRefTypeUnique.is_union = false;
  static const std::tuple<int32_t, const char*, bool, std::unique_ptr<MetadataTypeInterface>>
  module_StructWithRefTypeUnique_fields[] = {
    std::make_tuple(1, "def_field", false, std::make_unique<Struct< ::cpp2::Empty>>("module.Empty")),
    std::make_tuple(2, "opt_field", true, std::make_unique<Struct< ::cpp2::Empty>>("module.Empty")),
    std::make_tuple(3, "req_field", false, std::make_unique<Struct< ::cpp2::Empty>>("module.Empty")),
  };
  for (const auto& f : module_StructWithRefTypeUnique_fields) {
    ::apache::thrift::metadata::ThriftField field;
    field.id = std::get<0>(f);
    field.name = std::get<1>(f);
    field.is_optional = std::get<2>(f);
    std::get<3>(f)->writeAndGenType(field.type, metadata);
    module_StructWithRefTypeUnique.fields.push_back(std::move(field));
  }
}
void StructMetadata<::cpp2::StructWithRefTypeShared>::gen(ThriftMetadata& metadata) {
  auto res = metadata.structs.emplace("module.StructWithRefTypeShared", ::apache::thrift::metadata::ThriftStruct{});
  if (!res.second) {
    return;
  }
  ::apache::thrift::metadata::ThriftStruct& module_StructWithRefTypeShared = res.first->second;
  module_StructWithRefTypeShared.name = "module.StructWithRefTypeShared";
  module_StructWithRefTypeShared.is_union = false;
  static const std::tuple<int32_t, const char*, bool, std::unique_ptr<MetadataTypeInterface>>
  module_StructWithRefTypeShared_fields[] = {
    std::make_tuple(1, "def_field", false, std::make_unique<Struct< ::cpp2::Empty>>("module.Empty")),
    std::make_tuple(2, "opt_field", true, std::make_unique<Struct< ::cpp2::Empty>>("module.Empty")),
    std::make_tuple(3, "req_field", false, std::make_unique<Struct< ::cpp2::Empty>>("module.Empty")),
  };
  for (const auto& f : module_StructWithRefTypeShared_fields) {
    ::apache::thrift::metadata::ThriftField field;
    field.id = std::get<0>(f);
    field.name = std::get<1>(f);
    field.is_optional = std::get<2>(f);
    std::get<3>(f)->writeAndGenType(field.type, metadata);
    module_StructWithRefTypeShared.fields.push_back(std::move(field));
  }
}
void StructMetadata<::cpp2::StructWithRefTypeSharedConst>::gen(ThriftMetadata& metadata) {
  auto res = metadata.structs.emplace("module.StructWithRefTypeSharedConst", ::apache::thrift::metadata::ThriftStruct{});
  if (!res.second) {
    return;
  }
  ::apache::thrift::metadata::ThriftStruct& module_StructWithRefTypeSharedConst = res.first->second;
  module_StructWithRefTypeSharedConst.name = "module.StructWithRefTypeSharedConst";
  module_StructWithRefTypeSharedConst.is_union = false;
  static const std::tuple<int32_t, const char*, bool, std::unique_ptr<MetadataTypeInterface>>
  module_StructWithRefTypeSharedConst_fields[] = {
    std::make_tuple(1, "def_field", false, std::make_unique<Struct< ::cpp2::Empty>>("module.Empty")),
    std::make_tuple(2, "opt_field", true, std::make_unique<Struct< ::cpp2::Empty>>("module.Empty")),
    std::make_tuple(3, "req_field", false, std::make_unique<Struct< ::cpp2::Empty>>("module.Empty")),
  };
  for (const auto& f : module_StructWithRefTypeSharedConst_fields) {
    ::apache::thrift::metadata::ThriftField field;
    field.id = std::get<0>(f);
    field.name = std::get<1>(f);
    field.is_optional = std::get<2>(f);
    std::get<3>(f)->writeAndGenType(field.type, metadata);
    module_StructWithRefTypeSharedConst.fields.push_back(std::move(field));
  }
}
void StructMetadata<::cpp2::StructWithRefAndAnnotCppNoexceptMoveCtor>::gen(ThriftMetadata& metadata) {
  auto res = metadata.structs.emplace("module.StructWithRefAndAnnotCppNoexceptMoveCtor", ::apache::thrift::metadata::ThriftStruct{});
  if (!res.second) {
    return;
  }
  ::apache::thrift::metadata::ThriftStruct& module_StructWithRefAndAnnotCppNoexceptMoveCtor = res.first->second;
  module_StructWithRefAndAnnotCppNoexceptMoveCtor.name = "module.StructWithRefAndAnnotCppNoexceptMoveCtor";
  module_StructWithRefAndAnnotCppNoexceptMoveCtor.is_union = false;
  static const std::tuple<int32_t, const char*, bool, std::unique_ptr<MetadataTypeInterface>>
  module_StructWithRefAndAnnotCppNoexceptMoveCtor_fields[] = {
    std::make_tuple(1, "def_field", false, std::make_unique<Struct< ::cpp2::Empty>>("module.Empty")),
  };
  for (const auto& f : module_StructWithRefAndAnnotCppNoexceptMoveCtor_fields) {
    ::apache::thrift::metadata::ThriftField field;
    field.id = std::get<0>(f);
    field.name = std::get<1>(f);
    field.is_optional = std::get<2>(f);
    std::get<3>(f)->writeAndGenType(field.type, metadata);
    module_StructWithRefAndAnnotCppNoexceptMoveCtor.fields.push_back(std::move(field));
  }
}

} // namespace md
} // namespace detail
} // namespace thrift
} // namespace apache
