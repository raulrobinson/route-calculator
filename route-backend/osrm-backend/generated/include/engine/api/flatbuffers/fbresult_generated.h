// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_FBRESULT_OSRM_ENGINE_API_FBRESULT_H_
#define FLATBUFFERS_GENERATED_FBRESULT_OSRM_ENGINE_API_FBRESULT_H_

#include "flatbuffers/flatbuffers.h"

// Ensure the included flatbuffers.h is the same version as when this file was
// generated, otherwise it may not be compatible.
static_assert(FLATBUFFERS_VERSION_MAJOR == 24 &&
              FLATBUFFERS_VERSION_MINOR == 3 &&
              FLATBUFFERS_VERSION_REVISION == 25,
             "Non-compatible flatbuffers version included");

#include "route_generated.h"
#include "table_generated.h"

namespace osrm {
namespace engine {
namespace api {
namespace fbresult {

struct Error;
struct ErrorBuilder;

struct FBResult;
struct FBResultBuilder;

struct Error FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef ErrorBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_CODE = 4,
    VT_MESSAGE = 6
  };
  const ::flatbuffers::String *code() const {
    return GetPointer<const ::flatbuffers::String *>(VT_CODE);
  }
  const ::flatbuffers::String *message() const {
    return GetPointer<const ::flatbuffers::String *>(VT_MESSAGE);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_CODE) &&
           verifier.VerifyString(code()) &&
           VerifyOffset(verifier, VT_MESSAGE) &&
           verifier.VerifyString(message()) &&
           verifier.EndTable();
  }
};

struct ErrorBuilder {
  typedef Error Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_code(::flatbuffers::Offset<::flatbuffers::String> code) {
    fbb_.AddOffset(Error::VT_CODE, code);
  }
  void add_message(::flatbuffers::Offset<::flatbuffers::String> message) {
    fbb_.AddOffset(Error::VT_MESSAGE, message);
  }
  explicit ErrorBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<Error> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<Error>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<Error> CreateError(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    ::flatbuffers::Offset<::flatbuffers::String> code = 0,
    ::flatbuffers::Offset<::flatbuffers::String> message = 0) {
  ErrorBuilder builder_(_fbb);
  builder_.add_message(message);
  builder_.add_code(code);
  return builder_.Finish();
}

inline ::flatbuffers::Offset<Error> CreateErrorDirect(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    const char *code = nullptr,
    const char *message = nullptr) {
  auto code__ = code ? _fbb.CreateString(code) : 0;
  auto message__ = message ? _fbb.CreateString(message) : 0;
  return osrm::engine::api::fbresult::CreateError(
      _fbb,
      code__,
      message__);
}

struct FBResult FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef FBResultBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_ERROR = 4,
    VT_CODE = 6,
    VT_DATA_VERSION = 8,
    VT_WAYPOINTS = 10,
    VT_ROUTES = 12,
    VT_TABLE = 14
  };
  bool error() const {
    return GetField<uint8_t>(VT_ERROR, 0) != 0;
  }
  const osrm::engine::api::fbresult::Error *code() const {
    return GetPointer<const osrm::engine::api::fbresult::Error *>(VT_CODE);
  }
  const ::flatbuffers::String *data_version() const {
    return GetPointer<const ::flatbuffers::String *>(VT_DATA_VERSION);
  }
  const ::flatbuffers::Vector<::flatbuffers::Offset<osrm::engine::api::fbresult::Waypoint>> *waypoints() const {
    return GetPointer<const ::flatbuffers::Vector<::flatbuffers::Offset<osrm::engine::api::fbresult::Waypoint>> *>(VT_WAYPOINTS);
  }
  const ::flatbuffers::Vector<::flatbuffers::Offset<osrm::engine::api::fbresult::RouteObject>> *routes() const {
    return GetPointer<const ::flatbuffers::Vector<::flatbuffers::Offset<osrm::engine::api::fbresult::RouteObject>> *>(VT_ROUTES);
  }
  const osrm::engine::api::fbresult::TableResult *table() const {
    return GetPointer<const osrm::engine::api::fbresult::TableResult *>(VT_TABLE);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint8_t>(verifier, VT_ERROR, 1) &&
           VerifyOffset(verifier, VT_CODE) &&
           verifier.VerifyTable(code()) &&
           VerifyOffset(verifier, VT_DATA_VERSION) &&
           verifier.VerifyString(data_version()) &&
           VerifyOffset(verifier, VT_WAYPOINTS) &&
           verifier.VerifyVector(waypoints()) &&
           verifier.VerifyVectorOfTables(waypoints()) &&
           VerifyOffset(verifier, VT_ROUTES) &&
           verifier.VerifyVector(routes()) &&
           verifier.VerifyVectorOfTables(routes()) &&
           VerifyOffset(verifier, VT_TABLE) &&
           verifier.VerifyTable(table()) &&
           verifier.EndTable();
  }
};

struct FBResultBuilder {
  typedef FBResult Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_error(bool error) {
    fbb_.AddElement<uint8_t>(FBResult::VT_ERROR, static_cast<uint8_t>(error), 0);
  }
  void add_code(::flatbuffers::Offset<osrm::engine::api::fbresult::Error> code) {
    fbb_.AddOffset(FBResult::VT_CODE, code);
  }
  void add_data_version(::flatbuffers::Offset<::flatbuffers::String> data_version) {
    fbb_.AddOffset(FBResult::VT_DATA_VERSION, data_version);
  }
  void add_waypoints(::flatbuffers::Offset<::flatbuffers::Vector<::flatbuffers::Offset<osrm::engine::api::fbresult::Waypoint>>> waypoints) {
    fbb_.AddOffset(FBResult::VT_WAYPOINTS, waypoints);
  }
  void add_routes(::flatbuffers::Offset<::flatbuffers::Vector<::flatbuffers::Offset<osrm::engine::api::fbresult::RouteObject>>> routes) {
    fbb_.AddOffset(FBResult::VT_ROUTES, routes);
  }
  void add_table(::flatbuffers::Offset<osrm::engine::api::fbresult::TableResult> table) {
    fbb_.AddOffset(FBResult::VT_TABLE, table);
  }
  explicit FBResultBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<FBResult> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<FBResult>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<FBResult> CreateFBResult(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    bool error = false,
    ::flatbuffers::Offset<osrm::engine::api::fbresult::Error> code = 0,
    ::flatbuffers::Offset<::flatbuffers::String> data_version = 0,
    ::flatbuffers::Offset<::flatbuffers::Vector<::flatbuffers::Offset<osrm::engine::api::fbresult::Waypoint>>> waypoints = 0,
    ::flatbuffers::Offset<::flatbuffers::Vector<::flatbuffers::Offset<osrm::engine::api::fbresult::RouteObject>>> routes = 0,
    ::flatbuffers::Offset<osrm::engine::api::fbresult::TableResult> table = 0) {
  FBResultBuilder builder_(_fbb);
  builder_.add_table(table);
  builder_.add_routes(routes);
  builder_.add_waypoints(waypoints);
  builder_.add_data_version(data_version);
  builder_.add_code(code);
  builder_.add_error(error);
  return builder_.Finish();
}

inline ::flatbuffers::Offset<FBResult> CreateFBResultDirect(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    bool error = false,
    ::flatbuffers::Offset<osrm::engine::api::fbresult::Error> code = 0,
    const char *data_version = nullptr,
    const std::vector<::flatbuffers::Offset<osrm::engine::api::fbresult::Waypoint>> *waypoints = nullptr,
    const std::vector<::flatbuffers::Offset<osrm::engine::api::fbresult::RouteObject>> *routes = nullptr,
    ::flatbuffers::Offset<osrm::engine::api::fbresult::TableResult> table = 0) {
  auto data_version__ = data_version ? _fbb.CreateString(data_version) : 0;
  auto waypoints__ = waypoints ? _fbb.CreateVector<::flatbuffers::Offset<osrm::engine::api::fbresult::Waypoint>>(*waypoints) : 0;
  auto routes__ = routes ? _fbb.CreateVector<::flatbuffers::Offset<osrm::engine::api::fbresult::RouteObject>>(*routes) : 0;
  return osrm::engine::api::fbresult::CreateFBResult(
      _fbb,
      error,
      code,
      data_version__,
      waypoints__,
      routes__,
      table);
}

inline const osrm::engine::api::fbresult::FBResult *GetFBResult(const void *buf) {
  return ::flatbuffers::GetRoot<osrm::engine::api::fbresult::FBResult>(buf);
}

inline const osrm::engine::api::fbresult::FBResult *GetSizePrefixedFBResult(const void *buf) {
  return ::flatbuffers::GetSizePrefixedRoot<osrm::engine::api::fbresult::FBResult>(buf);
}

inline bool VerifyFBResultBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<osrm::engine::api::fbresult::FBResult>(nullptr);
}

inline bool VerifySizePrefixedFBResultBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<osrm::engine::api::fbresult::FBResult>(nullptr);
}

inline void FinishFBResultBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<osrm::engine::api::fbresult::FBResult> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedFBResultBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<osrm::engine::api::fbresult::FBResult> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace fbresult
}  // namespace api
}  // namespace engine
}  // namespace osrm

#endif  // FLATBUFFERS_GENERATED_FBRESULT_OSRM_ENGINE_API_FBRESULT_H_
