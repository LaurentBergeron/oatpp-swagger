/***************************************************************************
 *
 * Project         _____    __   ____   _      _
 *                (  _  )  /__\ (_  _)_| |_  _| |_
 *                 )(_)(  /(__)\  )( (_   _)(_   _)
 *                (_____)(__)(__)(__)  |_|    |_|
 *
 *
 * Copyright 2018-present, Leonid Stryzhevskyi, <lganzzzo@gmail.com>
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
 *
 ***************************************************************************/

#ifndef oatpp_swagger_oas3_Model_hpp
#define oatpp_swagger_oas3_Model_hpp

#include "oatpp/core/data/mapping/type/Object.hpp"
#include "oatpp/core/macro/codegen.hpp"

namespace oatpp { namespace swagger { namespace oas3 {
#include OATPP_CODEGEN_BEGIN(DTO)
  
class Contact : public oatpp::data::mapping::type::Object {
  
  DTO_INIT(Contact, Object)
  
  DTO_FIELD(String, name);
  DTO_FIELD(String, url);
  DTO_FIELD(String, email);
  
};

class License : public oatpp::data::mapping::type::Object {
  
  DTO_INIT(License, Object)
  
  DTO_FIELD(String, name);
  DTO_FIELD(String, url);
  
};

class Info : public oatpp::data::mapping::type::Object {
  
  DTO_INIT(Info, Object)
  
  DTO_FIELD(String, title);
  DTO_FIELD(String, description);
  DTO_FIELD(String, termsOfService);
  DTO_FIELD(Contact::ObjectWrapper, contact);
  DTO_FIELD(License::ObjectWrapper, license);
  DTO_FIELD(String, version);
  
};

class Server : public oatpp::data::mapping::type::Object {
  
  DTO_INIT(Server, Object)
  
  DTO_FIELD(String, url);
  
};
  
class Schema : public oatpp::data::mapping::type::Object {
  
  DTO_INIT(Schema, Object)
  
  DTO_FIELD(String, type); // integer, string
  DTO_FIELD(String, format); // int32, int64
  DTO_FIELD(Fields<Schema::ObjectWrapper>::ObjectWrapper, properties);
  DTO_FIELD(Schema::ObjectWrapper, items);
  
};
  
class MediaTypeObject : public oatpp::data::mapping::type::Object {
  
  DTO_INIT(MediaTypeObject, Object)
  
  DTO_FIELD(Schema::ObjectWrapper, schema);
  
};
  
class OperationResponse : public oatpp::data::mapping::type::Object {
  
  DTO_INIT(OperationResponse, Object)
  
  DTO_FIELD(String, description);
  DTO_FIELD(Fields<MediaTypeObject::ObjectWrapper>::ObjectWrapper, content);
  
};
  
class RequestBody : public oatpp::data::mapping::type::Object {
  
  DTO_INIT(RequestBody, Object)
  
  DTO_FIELD(String, description);
  DTO_FIELD(Fields<MediaTypeObject::ObjectWrapper>::ObjectWrapper, content);
  
};
  
class PathItemOperation : public oatpp::data::mapping::type::Object {
  
  DTO_INIT(PathItemOperation, Object)
  
  DTO_FIELD(String, description);
  DTO_FIELD(String, summary);
  DTO_FIELD(String, operationId);
  DTO_FIELD(RequestBody::ObjectWrapper, requestBody);
  DTO_FIELD(List<String>::ObjectWrapper, tags);
  DTO_FIELD(Fields<OperationResponse::ObjectWrapper>::ObjectWrapper, responses);
  
};
  
class PathItemParameter : public oatpp::data::mapping::type::Object {
  
  DTO_INIT(PathItemParameter, Object)
  
  DTO_FIELD(String, name);
  DTO_FIELD(String, in); // "query", "header", "path"
  DTO_FIELD(Schema::ObjectWrapper, schema);
  
};
  
class PathItem : public oatpp::data::mapping::type::Object {
  
  DTO_INIT(PathItem, Object)
  
  DTO_FIELD(PathItemOperation::ObjectWrapper, operationGet, "get");
  DTO_FIELD(PathItemOperation::ObjectWrapper, operationPut, "put");
  DTO_FIELD(PathItemOperation::ObjectWrapper, operationPost, "post");
  DTO_FIELD(PathItemOperation::ObjectWrapper, operationDelete, "delete");
  DTO_FIELD(PathItemOperation::ObjectWrapper, operationOptions, "options");
  DTO_FIELD(PathItemOperation::ObjectWrapper, operationHead, "head");
  DTO_FIELD(PathItemOperation::ObjectWrapper, operationPatch, "patch");
  DTO_FIELD(PathItemOperation::ObjectWrapper, operationTrace, "trace");
  
  DTO_FIELD(List<PathItemParameter::ObjectWrapper>::ObjectWrapper, parameters);
  
};

class Document : public oatpp::data::mapping::type::Object {
  
  DTO_INIT(Document, Object)
  
  DTO_FIELD(String, openapi, "openapi") = "3.0.0";
  DTO_FIELD(Info::ObjectWrapper, info);
  DTO_FIELD(List<Server::ObjectWrapper>::ObjectWrapper, servers);
  DTO_FIELD(Fields<PathItem::ObjectWrapper>::ObjectWrapper, paths);
  
};
  
#include OATPP_CODEGEN_END(DTO)
}}}

#endif /* oatpp_swagger_oas3_Model_hpp */
