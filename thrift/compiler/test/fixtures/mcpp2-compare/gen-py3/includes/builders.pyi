#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#

import typing as _typing

import folly.iobuf as __iobuf
import thrift.py3.builder


import includes.types as _includes_types


class AStruct_Builder(thrift.py3.builder.StructBuilder):
    FieldA: _typing.Optional[int]

    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Any]]: ...


class AStructB_Builder(thrift.py3.builder.StructBuilder):
    FieldA: _typing.Any

    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Any]]: ...

