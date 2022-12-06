#include <stdint.h>
#include "constants.h"
#include "row.h"
#include "cursor.h"
#ifndef NODE_H
#define NODE_H

typedef enum { NODE_INTERNAL, NODE_LEAF } NodeType;

/*
  Common Node Header Layout
*/

  static const uint32_t NODE_TYPE_SIZE = sizeof(uint8_t);
  static const uint32_t NODE_TYPE_OFFSET = 0;
  static const uint32_t IS_ROOT_SIZE = sizeof(uint8_t);
  static const uint32_t IS_ROOT_OFFSET = NODE_TYPE_SIZE;
  static const uint32_t PARENT_POINTER_SIZE = sizeof(uint32_t);
  static const uint32_t PARENT_POINTER_OFFSET = IS_ROOT_OFFSET + IS_ROOT_SIZE;
  static const uint32_t COMMON_NODE_HEADER_SIZE = NODE_TYPE_SIZE + IS_ROOT_SIZE + PARENT_POINTER_SIZE;

/*
  Leaf Node Header Layout
*/

  static const uint32_t LEAF_NODE_NUM_CELLS_SIZE = sizeof(uint32_t);
  static const uint32_t LEAF_NODE_NUM_CELLS_OFFSET = COMMON_NODE_HEADER_SIZE;
  static const uint32_t LEAF_NODE_HEADER_SIZE = COMMON_NODE_HEADER_SIZE + LEAF_NODE_NUM_CELLS_SIZE;

/*
  Leaf Node Body Layout
*/

  static const uint32_t LEAF_NODE_KEY_SIZE = sizeof(uint32_t);
  static const uint32_t LEAF_NODE_KEY_OFFSET = 0;
  static const uint32_t LEAF_NODE_VALUE_SIZE = ROW_SIZE;
  static const uint32_t LEAF_NODE_VALUE_OFFSET = LEAF_NODE_KEY_OFFSET + LEAF_NODE_KEY_SIZE;
  static const uint32_t LEAF_NODE_CELL_SIZE = LEAF_NODE_KEY_SIZE + LEAF_NODE_VALUE_SIZE;
  static const uint32_t LEAF_NODE_SPACE_FOR_CELLS = PAGE_SIZE - LEAF_NODE_HEADER_SIZE;
  static const uint32_t LEAF_NODE_MAX_CELLS = LEAF_NODE_SPACE_FOR_CELLS / LEAF_NODE_CELL_SIZE;

  uint32_t* leaf_node_num_cells(void* node);
  void* leaf_node_cell(void* node, uint32_t cell_num);
  uint32_t* leaf_node_key(void* node, uint32_t cell_num);
  void* leaf_node_value(void* node, uint32_t cell_num);
  void initialize_leaf_node(void* node);
  void leaf_node_insert(Cursor* cursor, uint32_t key, Row* value);

#endif
