/******************************************************************************
 * graph_io_stream.h
 * *
 * Source of KaHIP -- Karlsruhe High Quality Partitioning.
 * Christian Schulz <christian.schulz.phone@gmail.com>
 *****************************************************************************/

#ifndef GRAPHIOSTREAM_H_
#define GRAPHIOSTREAM_H_

#include <fstream>
#include <iostream>
#include <limits>
#include <ostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <set>
#include <unordered_map>
#include <list>
#include <algorithm>

#include "definitions.h"
#include "data_structure/graph_access.h"
#include "partition/partition_config.h"
#include "timer.h"
#include "random_functions.h"
#include "data_structure/buffered_map.h"

typedef std::vector<std::string>* LINE_BUFFER;

class graph_io_stream {
        public:
                graph_io_stream();
                virtual ~graph_io_stream () ;

                static
		NodeID createModel (PartitionConfig & config, graph_access & G, std::vector<std::vector<LongNodeID>>* &input);

                static
		void processNodeWeight(PartitionConfig & config, std::vector<NodeWeight>& all_nodes, NodeID node, NodeWeight weight, LongNodeID global_node);

                static
                void generalizeStreamPartition(PartitionConfig & config, graph_access & G_local);

                static
		void countAssignedNodes(PartitionConfig & config);

                static
                void onePassPartition(PartitionConfig & config, std::vector<std::vector<EdgeWeight>> & edges_virtualReal,
					std::vector<PartitionID> & blockVirtualToReal, std::vector<NodeWeight> & weight_VirtualBlocks);

		static
		int onePassDecide(PartitionConfig & config, NodeID node, std::vector<EdgeWeight> & edges_i_real);

		static
		double getFennelWeight(PartitionConfig & partition_config);

                static
		void writePartitionStream(PartitionConfig & config, const std::string & filename);

                static
		void readFirstLineStream(PartitionConfig & partition_config, std::string graph_filename, EdgeWeight& total_edge_cut);

                static
		void loadRemainingLines(PartitionConfig & partition_config, LINE_BUFFER &lines);

                static
		void loadBufferLines(PartitionConfig & partition_config, LINE_BUFFER &lines, LongNodeID num_lines);

                static
		std::vector<std::string>* loadLinesFromStream(PartitionConfig & partition_config, LongNodeID num_lines);

                static
		void sortBatchByDegree(PartitionConfig & config);

                static
		void createGraphForBatch(PartitionConfig & config, graph_access & G, NodeID node_counter, EdgeID edge_counter,
			std::vector<std::vector<std::pair<NodeID,EdgeWeight>>>& all_edges, std::vector<NodeWeight>& all_nodes, std::vector<NodeWeight>& all_assigned_ghost_nodes);

                static
		void recoverBlockAssignedToNode(PartitionConfig & config, graph_access & G, NodeID node, NodeID node_counter);

                static
		void setupForGhostNeighbors(PartitionConfig & config);

                static
		void processGhostNeighborInBatch(PartitionConfig & config, NodeID node, LongNodeID ghost_target, EdgeWeight edge_weight);

                static
		void processQuotientEdgeInBatch(PartitionConfig & config, NodeID node, LongNodeID global_target, EdgeWeight edge_weight);

                static
		EdgeID insertRegularEdgeInBatch(PartitionConfig & config, std::vector<std::vector<std::pair<NodeID,EdgeWeight>>>& all_edges,
										NodeID node, NodeID target, EdgeWeight edge_weight);

                static
		NodeID mapGhostKeysToNodesInBatch(PartitionConfig & config, std::vector<std::vector<std::pair<NodeID,EdgeWeight>>>& all_edges,
							std::vector<NodeWeight>& all_nodes, std::vector<NodeWeight>& all_assigned_ghost_nodes, NodeID& node_counter);

                static
		NodeID restreamMapGhostKeysToNodes(PartitionConfig & config);

                static
		NodeID greedyMapGhostKeysToNodes(PartitionConfig & config, std::vector<std::vector<std::pair<NodeID,EdgeWeight>>>& all_edges,
						std::vector<NodeWeight>& all_nodes, std::vector<NodeWeight>& all_assigned_ghost_nodes, NodeID& node_counter);

                static
		EdgeID insertGhostEdgesInBatch(PartitionConfig & config, std::vector<std::vector<std::pair<NodeID,EdgeWeight>>>& all_edgesInBatch);

                static
		void insertQuotientNodesInBatch(PartitionConfig & config, std::vector<NodeWeight>& all_nodes, NodeID uncontracted_ghost_nodes, NodeID& node_counter);

                static
		EdgeID insertQuotientEdgesInBatch(PartitionConfig & config, std::vector<std::vector<std::pair<NodeID,EdgeWeight>>>& all_edges, NodeID uncontracted_ghost_nodes);


                static
		EdgeID includeEdgeInBatch(std::vector<std::vector<std::pair<NodeID,EdgeWeight>>>& all_edges, NodeID node, NodeID target, EdgeWeight edge_weight);

                static
		void prescribeBufferInbalance(PartitionConfig & partition_config);

                static
		void streamEvaluatePartition(PartitionConfig & config, const std::string & filename, EdgeWeight& edgeCut);

                static
		void loadRemainingLinesToBinary(PartitionConfig & partition_config, std::vector<std::vector<LongNodeID>>* &input);

                static
		void loadBufferLinesToBinary(PartitionConfig & partition_config, std::vector<std::vector<LongNodeID>>* &input, LongNodeID num_lines);

                static
		std::vector<std::vector<LongNodeID>>* loadLinesFromStreamToBinary(PartitionConfig & partition_config, LongNodeID num_lines);

		template< typename T>
                static
		T return_and_delete_element(std::vector<T> & vec, LongNodeID pos);

//                static
//		int readEdgeStream_writeMetisBuffered(const std::string & graph_filename, std::string filename_output, bool relabel_nodes);

};

inline void graph_io_stream::loadRemainingLinesToBinary(PartitionConfig & partition_config, std::vector<std::vector<LongNodeID>>* &input) {
	if (partition_config.ram_stream) {
		input = graph_io_stream::loadLinesFromStreamToBinary(partition_config, partition_config.remaining_stream_nodes);
	}
}

inline void graph_io_stream::loadBufferLinesToBinary(PartitionConfig & partition_config, std::vector<std::vector<LongNodeID>>* &input, LongNodeID num_lines) {
	if (!partition_config.ram_stream) {
		input = graph_io_stream::loadLinesFromStreamToBinary(partition_config, num_lines);
	}
}

inline std::vector<std::vector<LongNodeID>>* graph_io_stream::loadLinesFromStreamToBinary(PartitionConfig & partition_config, LongNodeID num_lines) {
	std::vector<std::vector<LongNodeID>>* input;
	input = new std::vector<std::vector<LongNodeID>>(num_lines);
	std::vector<std::string>* lines;
	lines = new std::vector<std::string>(1);
	LongNodeID node_counter = 0;
	buffered_input *ss2 = NULL;
	bool is_first_batch = partition_config.curr_batch == 0;
	bool is_last_batch = partition_config.remaining_stream_nodes == partition_config.nmbNodes;
	bool is_second_last_batch = partition_config.remaining_stream_nodes <= 2*partition_config.nmbNodes;
	int MAX_DELAYED_NODES = partition_config.nmbNodes/2;
	int max_capacity_delayed_nodes = is_second_last_batch ? (partition_config.remaining_stream_nodes - partition_config.nmbNodes < MAX_DELAYED_NODES ? partition_config.remaining_stream_nodes - partition_config.nmbNodes : MAX_DELAYED_NODES) : MAX_DELAYED_NODES;
	float largest_ratio_to_be_delayed = 0.1;

	std::fill(partition_config.node_in_current_block->begin(), partition_config.node_in_current_block->end(), 0);

	unsigned i=0;
	while (partition_config.num_nodes_delayed > 0) {
		std::vector<LongNodeID> *line = &(*partition_config.delayed_lines)[i++];
		(*input)[node_counter++] = (*line);
		(*partition_config.node_in_current_block)[(*line)[0]-1] = 1; // line[0] == global_node_id
		partition_config.num_nodes_delayed--;
	}

	while( node_counter < num_lines) {
		if (partition_config.stream_in->eof()) {
			while (partition_config.num_nodes_delayed > 0) {
				if (node_counter >= num_lines)
					break;
				std::vector<LongNodeID> *line = &(*partition_config.delayed_lines)[--partition_config.num_nodes_delayed];
				(*input)[node_counter++] = (*line);
				(*partition_config.node_in_current_block)[(*line)[0]-1] = 1; // line[0] == global_node_id
			}
			break;

		}

		std::getline(*(partition_config.stream_in),(*lines)[0]);
		if ((*lines)[0][0] == '%') { // a comment in the file
			continue;
		}
		ss2 = new buffered_input(lines);
		LongNodeID global_node_id = partition_config.total_nodes_loaded+1;
		std::vector<LongNodeID> *new_line = &(*input)[node_counter];
		new_line->clear();
		new_line->push_back(global_node_id);
		ss2->simple_scan_line((*new_line), false);

		// Check if line should be delayed -> append to delayed nodes else append to input
		bool should_be_delayed = false;
		if (!is_first_batch && !is_last_batch) {
			bool delayed_nodes_has_capacity = partition_config.num_nodes_delayed < max_capacity_delayed_nodes;
			if (delayed_nodes_has_capacity) {
				// check if node should be delayed
				unsigned num_neighbours = new_line->size() - 1;
				unsigned num_of_neighours_partitioned = 0;
				for (unsigned i = 1; i < new_line->size(); i++) {
					LongNodeID target = (*new_line)[i];
					if ((*partition_config.stream_nodes_assign)[target-1] != INVALID_PARTITION) {
						num_of_neighours_partitioned++;
					}
				}
				float ratio = num_neighbours > 0 ? num_of_neighours_partitioned / (float) num_neighbours : 1;
				should_be_delayed = ratio <= largest_ratio_to_be_delayed;
			}
		}

		if (should_be_delayed) {
			(*partition_config.delayed_lines)[partition_config.num_nodes_delayed++] = *new_line;
		} else {
			node_counter++;
			(*partition_config.node_in_current_block)[global_node_id-1] = 1;
		}

		(*lines)[0].clear(); delete ss2;
		partition_config.total_nodes_loaded++;
	}


	delete lines;
	return input;
}



#endif /*GRAPHIOSTREAM_H_*/
