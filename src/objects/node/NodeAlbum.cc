#include "NodeAlbum.h"

Handle<Value> NodeAlbum::getName(Local<String> property, const AccessorInfo& info) {
  NodeAlbum* nodeAlbum = node::ObjectWrap::Unwrap<NodeAlbum>(info.Holder());
  return String::New(nodeAlbum->album->name.c_str());
}

Handle<Value> NodeAlbum::getCoverBase64(const Arguments& args) {
  HandleScope scope;
  NodeAlbum* nodeAlbum = node::ObjectWrap::Unwrap<NodeAlbum>(args.This());
  if(nodeAlbum->album->coverBase64 != 0) {
    return scope.Close(String::New(nodeAlbum->album->coverBase64));
  }
  return scope.Close(Undefined());
}

void NodeAlbum::init() {
  HandleScope scope;
  Handle<FunctionTemplate> constructorTemplate = NodeWrapped::init("Album");
  constructorTemplate->InstanceTemplate()->SetAccessor(String::NewSymbol("name"), getName, emptySetter);
  NODE_SET_PROTOTYPE_METHOD(constructorTemplate, "getCoverBase64", getCoverBase64);
  constructor = Persistent<Function>::New(constructorTemplate->GetFunction());
  scope.Close(Undefined());
}