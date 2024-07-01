// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_PARTITIONINFO_PARTITIONINFO_H_
#define FLATBUFFERS_GENERATED_PARTITIONINFO_PARTITIONINFO_H_

#include "flatbuffers/flatbuffers.h"

// Ensure the included flatbuffers.h is the same version as when this file was
// generated, otherwise it may not be compatible.
static_assert(FLATBUFFERS_VERSION_MAJOR == 24 &&
              FLATBUFFERS_VERSION_MINOR == 3 &&
              FLATBUFFERS_VERSION_REVISION == 25,
             "Non-compatible flatbuffers version included");

namespace PartitionInfo {

struct PartitionLog;
struct PartitionLogBuilder;

struct GraphMetadata;
struct GraphMetadataBuilder;

struct PartitionConfiguration;
struct PartitionConfigurationBuilder;

struct RunTime;
struct RunTimeBuilder;

struct PartitionMetrics;
struct PartitionMetricsBuilder;

struct MemoryConsumption;
struct MemoryConsumptionBuilder;

struct PartitionLog FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef PartitionLogBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_GRAPH_METADATA = 4,
    VT_PARTITION_CONFIGURATION = 6,
    VT_RUNTIME = 8,
    VT_MEMORY_CONSUMPTION = 10,
    VT_METRICS = 12
  };
  const PartitionInfo::GraphMetadata *graph_metadata() const {
    return GetPointer<const PartitionInfo::GraphMetadata *>(VT_GRAPH_METADATA);
  }
  const PartitionInfo::PartitionConfiguration *partition_configuration() const {
    return GetPointer<const PartitionInfo::PartitionConfiguration *>(VT_PARTITION_CONFIGURATION);
  }
  const PartitionInfo::RunTime *runtime() const {
    return GetPointer<const PartitionInfo::RunTime *>(VT_RUNTIME);
  }
  const PartitionInfo::MemoryConsumption *memory_consumption() const {
    return GetPointer<const PartitionInfo::MemoryConsumption *>(VT_MEMORY_CONSUMPTION);
  }
  const PartitionInfo::PartitionMetrics *metrics() const {
    return GetPointer<const PartitionInfo::PartitionMetrics *>(VT_METRICS);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_GRAPH_METADATA) &&
           verifier.VerifyTable(graph_metadata()) &&
           VerifyOffset(verifier, VT_PARTITION_CONFIGURATION) &&
           verifier.VerifyTable(partition_configuration()) &&
           VerifyOffset(verifier, VT_RUNTIME) &&
           verifier.VerifyTable(runtime()) &&
           VerifyOffset(verifier, VT_MEMORY_CONSUMPTION) &&
           verifier.VerifyTable(memory_consumption()) &&
           VerifyOffset(verifier, VT_METRICS) &&
           verifier.VerifyTable(metrics()) &&
           verifier.EndTable();
  }
};

struct PartitionLogBuilder {
  typedef PartitionLog Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_graph_metadata(::flatbuffers::Offset<PartitionInfo::GraphMetadata> graph_metadata) {
    fbb_.AddOffset(PartitionLog::VT_GRAPH_METADATA, graph_metadata);
  }
  void add_partition_configuration(::flatbuffers::Offset<PartitionInfo::PartitionConfiguration> partition_configuration) {
    fbb_.AddOffset(PartitionLog::VT_PARTITION_CONFIGURATION, partition_configuration);
  }
  void add_runtime(::flatbuffers::Offset<PartitionInfo::RunTime> runtime) {
    fbb_.AddOffset(PartitionLog::VT_RUNTIME, runtime);
  }
  void add_memory_consumption(::flatbuffers::Offset<PartitionInfo::MemoryConsumption> memory_consumption) {
    fbb_.AddOffset(PartitionLog::VT_MEMORY_CONSUMPTION, memory_consumption);
  }
  void add_metrics(::flatbuffers::Offset<PartitionInfo::PartitionMetrics> metrics) {
    fbb_.AddOffset(PartitionLog::VT_METRICS, metrics);
  }
  explicit PartitionLogBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<PartitionLog> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<PartitionLog>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<PartitionLog> CreatePartitionLog(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    ::flatbuffers::Offset<PartitionInfo::GraphMetadata> graph_metadata = 0,
    ::flatbuffers::Offset<PartitionInfo::PartitionConfiguration> partition_configuration = 0,
    ::flatbuffers::Offset<PartitionInfo::RunTime> runtime = 0,
    ::flatbuffers::Offset<PartitionInfo::MemoryConsumption> memory_consumption = 0,
    ::flatbuffers::Offset<PartitionInfo::PartitionMetrics> metrics = 0) {
  PartitionLogBuilder builder_(_fbb);
  builder_.add_metrics(metrics);
  builder_.add_memory_consumption(memory_consumption);
  builder_.add_runtime(runtime);
  builder_.add_partition_configuration(partition_configuration);
  builder_.add_graph_metadata(graph_metadata);
  return builder_.Finish();
}

struct GraphMetadata FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef GraphMetadataBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_FILENAME = 4,
    VT_NUM_NODES = 6,
    VT_NUM_EDGES = 8
  };
  const ::flatbuffers::String *filename() const {
    return GetPointer<const ::flatbuffers::String *>(VT_FILENAME);
  }
  uint64_t num_nodes() const {
    return GetField<uint64_t>(VT_NUM_NODES, 0);
  }
  uint64_t num_edges() const {
    return GetField<uint64_t>(VT_NUM_EDGES, 0);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_FILENAME) &&
           verifier.VerifyString(filename()) &&
           VerifyField<uint64_t>(verifier, VT_NUM_NODES, 8) &&
           VerifyField<uint64_t>(verifier, VT_NUM_EDGES, 8) &&
           verifier.EndTable();
  }
};

struct GraphMetadataBuilder {
  typedef GraphMetadata Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_filename(::flatbuffers::Offset<::flatbuffers::String> filename) {
    fbb_.AddOffset(GraphMetadata::VT_FILENAME, filename);
  }
  void add_num_nodes(uint64_t num_nodes) {
    fbb_.AddElement<uint64_t>(GraphMetadata::VT_NUM_NODES, num_nodes, 0);
  }
  void add_num_edges(uint64_t num_edges) {
    fbb_.AddElement<uint64_t>(GraphMetadata::VT_NUM_EDGES, num_edges, 0);
  }
  explicit GraphMetadataBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<GraphMetadata> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<GraphMetadata>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<GraphMetadata> CreateGraphMetadata(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    ::flatbuffers::Offset<::flatbuffers::String> filename = 0,
    uint64_t num_nodes = 0,
    uint64_t num_edges = 0) {
  GraphMetadataBuilder builder_(_fbb);
  builder_.add_num_edges(num_edges);
  builder_.add_num_nodes(num_nodes);
  builder_.add_filename(filename);
  return builder_.Finish();
}

inline ::flatbuffers::Offset<GraphMetadata> CreateGraphMetadataDirect(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    const char *filename = nullptr,
    uint64_t num_nodes = 0,
    uint64_t num_edges = 0) {
  auto filename__ = filename ? _fbb.CreateString(filename) : 0;
  return PartitionInfo::CreateGraphMetadata(
      _fbb,
      filename__,
      num_nodes,
      num_edges);
}

struct PartitionConfiguration FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef PartitionConfigurationBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_K = 4,
    VT_SEED = 6,
    VT_STREAM_BUFFER = 8,
    VT_MODEL_MODE = 10,
    VT_ALPHA = 12
  };
  uint32_t k() const {
    return GetField<uint32_t>(VT_K, 0);
  }
  int32_t seed() const {
    return GetField<int32_t>(VT_SEED, 0);
  }
  uint64_t stream_buffer() const {
    return GetField<uint64_t>(VT_STREAM_BUFFER, 0);
  }
  int32_t model_mode() const {
    return GetField<int32_t>(VT_MODEL_MODE, 0);
  }
  int32_t alpha() const {
    return GetField<int32_t>(VT_ALPHA, 0);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint32_t>(verifier, VT_K, 4) &&
           VerifyField<int32_t>(verifier, VT_SEED, 4) &&
           VerifyField<uint64_t>(verifier, VT_STREAM_BUFFER, 8) &&
           VerifyField<int32_t>(verifier, VT_MODEL_MODE, 4) &&
           VerifyField<int32_t>(verifier, VT_ALPHA, 4) &&
           verifier.EndTable();
  }
};

struct PartitionConfigurationBuilder {
  typedef PartitionConfiguration Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_k(uint32_t k) {
    fbb_.AddElement<uint32_t>(PartitionConfiguration::VT_K, k, 0);
  }
  void add_seed(int32_t seed) {
    fbb_.AddElement<int32_t>(PartitionConfiguration::VT_SEED, seed, 0);
  }
  void add_stream_buffer(uint64_t stream_buffer) {
    fbb_.AddElement<uint64_t>(PartitionConfiguration::VT_STREAM_BUFFER, stream_buffer, 0);
  }
  void add_model_mode(int32_t model_mode) {
    fbb_.AddElement<int32_t>(PartitionConfiguration::VT_MODEL_MODE, model_mode, 0);
  }
  void add_alpha(int32_t alpha) {
    fbb_.AddElement<int32_t>(PartitionConfiguration::VT_ALPHA, alpha, 0);
  }
  explicit PartitionConfigurationBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<PartitionConfiguration> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<PartitionConfiguration>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<PartitionConfiguration> CreatePartitionConfiguration(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    uint32_t k = 0,
    int32_t seed = 0,
    uint64_t stream_buffer = 0,
    int32_t model_mode = 0,
    int32_t alpha = 0) {
  PartitionConfigurationBuilder builder_(_fbb);
  builder_.add_stream_buffer(stream_buffer);
  builder_.add_alpha(alpha);
  builder_.add_model_mode(model_mode);
  builder_.add_seed(seed);
  builder_.add_k(k);
  return builder_.Finish();
}

struct RunTime FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef RunTimeBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_IO_TIME = 4,
    VT_PARTITION_TIME = 6,
    VT_MODEL_CONSTRUCTION_TIME = 8,
    VT_MAPPING_TIME = 10,
    VT_TOTAL_TIME = 12
  };
  double io_time() const {
    return GetField<double>(VT_IO_TIME, 0.0);
  }
  double partition_time() const {
    return GetField<double>(VT_PARTITION_TIME, 0.0);
  }
  double model_construction_time() const {
    return GetField<double>(VT_MODEL_CONSTRUCTION_TIME, 0.0);
  }
  double mapping_time() const {
    return GetField<double>(VT_MAPPING_TIME, 0.0);
  }
  double total_time() const {
    return GetField<double>(VT_TOTAL_TIME, 0.0);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<double>(verifier, VT_IO_TIME, 8) &&
           VerifyField<double>(verifier, VT_PARTITION_TIME, 8) &&
           VerifyField<double>(verifier, VT_MODEL_CONSTRUCTION_TIME, 8) &&
           VerifyField<double>(verifier, VT_MAPPING_TIME, 8) &&
           VerifyField<double>(verifier, VT_TOTAL_TIME, 8) &&
           verifier.EndTable();
  }
};

struct RunTimeBuilder {
  typedef RunTime Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_io_time(double io_time) {
    fbb_.AddElement<double>(RunTime::VT_IO_TIME, io_time, 0.0);
  }
  void add_partition_time(double partition_time) {
    fbb_.AddElement<double>(RunTime::VT_PARTITION_TIME, partition_time, 0.0);
  }
  void add_model_construction_time(double model_construction_time) {
    fbb_.AddElement<double>(RunTime::VT_MODEL_CONSTRUCTION_TIME, model_construction_time, 0.0);
  }
  void add_mapping_time(double mapping_time) {
    fbb_.AddElement<double>(RunTime::VT_MAPPING_TIME, mapping_time, 0.0);
  }
  void add_total_time(double total_time) {
    fbb_.AddElement<double>(RunTime::VT_TOTAL_TIME, total_time, 0.0);
  }
  explicit RunTimeBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<RunTime> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<RunTime>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<RunTime> CreateRunTime(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    double io_time = 0.0,
    double partition_time = 0.0,
    double model_construction_time = 0.0,
    double mapping_time = 0.0,
    double total_time = 0.0) {
  RunTimeBuilder builder_(_fbb);
  builder_.add_total_time(total_time);
  builder_.add_mapping_time(mapping_time);
  builder_.add_model_construction_time(model_construction_time);
  builder_.add_partition_time(partition_time);
  builder_.add_io_time(io_time);
  return builder_.Finish();
}

struct PartitionMetrics FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef PartitionMetricsBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_EDGE_CUT = 4,
    VT_VERTEX_CUT = 6,
    VT_REPLICAS = 8,
    VT_REPLICATION_FACTOR = 10,
    VT_BALANCE = 12
  };
  int32_t edge_cut() const {
    return GetField<int32_t>(VT_EDGE_CUT, 0);
  }
  uint32_t vertex_cut() const {
    return GetField<uint32_t>(VT_VERTEX_CUT, 0);
  }
  uint32_t replicas() const {
    return GetField<uint32_t>(VT_REPLICAS, 0);
  }
  double replication_factor() const {
    return GetField<double>(VT_REPLICATION_FACTOR, 0.0);
  }
  double balance() const {
    return GetField<double>(VT_BALANCE, 0.0);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_EDGE_CUT, 4) &&
           VerifyField<uint32_t>(verifier, VT_VERTEX_CUT, 4) &&
           VerifyField<uint32_t>(verifier, VT_REPLICAS, 4) &&
           VerifyField<double>(verifier, VT_REPLICATION_FACTOR, 8) &&
           VerifyField<double>(verifier, VT_BALANCE, 8) &&
           verifier.EndTable();
  }
};

struct PartitionMetricsBuilder {
  typedef PartitionMetrics Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_edge_cut(int32_t edge_cut) {
    fbb_.AddElement<int32_t>(PartitionMetrics::VT_EDGE_CUT, edge_cut, 0);
  }
  void add_vertex_cut(uint32_t vertex_cut) {
    fbb_.AddElement<uint32_t>(PartitionMetrics::VT_VERTEX_CUT, vertex_cut, 0);
  }
  void add_replicas(uint32_t replicas) {
    fbb_.AddElement<uint32_t>(PartitionMetrics::VT_REPLICAS, replicas, 0);
  }
  void add_replication_factor(double replication_factor) {
    fbb_.AddElement<double>(PartitionMetrics::VT_REPLICATION_FACTOR, replication_factor, 0.0);
  }
  void add_balance(double balance) {
    fbb_.AddElement<double>(PartitionMetrics::VT_BALANCE, balance, 0.0);
  }
  explicit PartitionMetricsBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<PartitionMetrics> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<PartitionMetrics>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<PartitionMetrics> CreatePartitionMetrics(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    int32_t edge_cut = 0,
    uint32_t vertex_cut = 0,
    uint32_t replicas = 0,
    double replication_factor = 0.0,
    double balance = 0.0) {
  PartitionMetricsBuilder builder_(_fbb);
  builder_.add_balance(balance);
  builder_.add_replication_factor(replication_factor);
  builder_.add_replicas(replicas);
  builder_.add_vertex_cut(vertex_cut);
  builder_.add_edge_cut(edge_cut);
  return builder_.Finish();
}

struct MemoryConsumption FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef MemoryConsumptionBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_MAX_RSS = 4
  };
  int64_t max_rss() const {
    return GetField<int64_t>(VT_MAX_RSS, 0);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int64_t>(verifier, VT_MAX_RSS, 8) &&
           verifier.EndTable();
  }
};

struct MemoryConsumptionBuilder {
  typedef MemoryConsumption Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_max_rss(int64_t max_rss) {
    fbb_.AddElement<int64_t>(MemoryConsumption::VT_MAX_RSS, max_rss, 0);
  }
  explicit MemoryConsumptionBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<MemoryConsumption> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<MemoryConsumption>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<MemoryConsumption> CreateMemoryConsumption(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    int64_t max_rss = 0) {
  MemoryConsumptionBuilder builder_(_fbb);
  builder_.add_max_rss(max_rss);
  return builder_.Finish();
}

inline const PartitionInfo::PartitionLog *GetPartitionLog(const void *buf) {
  return ::flatbuffers::GetRoot<PartitionInfo::PartitionLog>(buf);
}

inline const PartitionInfo::PartitionLog *GetSizePrefixedPartitionLog(const void *buf) {
  return ::flatbuffers::GetSizePrefixedRoot<PartitionInfo::PartitionLog>(buf);
}

inline bool VerifyPartitionLogBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<PartitionInfo::PartitionLog>(nullptr);
}

inline bool VerifySizePrefixedPartitionLogBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<PartitionInfo::PartitionLog>(nullptr);
}

inline void FinishPartitionLogBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<PartitionInfo::PartitionLog> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedPartitionLogBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<PartitionInfo::PartitionLog> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace PartitionInfo

#endif  // FLATBUFFERS_GENERATED_PARTITIONINFO_PARTITIONINFO_H_
