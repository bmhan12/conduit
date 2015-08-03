//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
// Copyright (c) 2014-2015, Lawrence Livermore National Security, LLC.
// 
// Produced at the Lawrence Livermore National Laboratory
// 
// LLNL-CODE-666778
// 
// All rights reserved.
// 
// This file is part of Conduit. 
// 
// For details, see: http://cyrush.github.io/conduit.
// 
// Please also read conduit/LICENSE
// 
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions are met:
// 
// * Redistributions of source code must retain the above copyright notice, 
//   this list of conditions and the disclaimer below.
// 
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the disclaimer (as noted below) in the
//   documentation and/or other materials provided with the distribution.
// 
// * Neither the name of the LLNS/LLNL nor the names of its contributors may
//   be used to endorse or promote products derived from this software without
//   specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL LAWRENCE LIVERMORE NATIONAL SECURITY,
// LLC, THE U.S. DEPARTMENT OF ENERGY OR CONTRIBUTORS BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
// DAMAGES  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
// OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
// IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
// POSSIBILITY OF SUCH DAMAGE.
// 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//


//-----------------------------------------------------------------------------
///
/// file: conduit_node.h
///
//-----------------------------------------------------------------------------

#ifndef CONDUIT_NODE_H
#define CONDUIT_NODE_H

#include <stdlib.h>
#include <stddef.h>
    
#include "Bitwidth_Style_Types.h"


//-----------------------------------------------------------------------------
// -- begin extern C
//-----------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------
// -- typedef for conduit_node --
//-----------------------------------------------------------------------------

typedef void  conduit_node;

//-----------------------------------------------------------------------------
// -- conduit_node creation and destruction --
//-----------------------------------------------------------------------------

conduit_node *conduit_node_create();
void          conduit_node_destroy(conduit_node *cnode);


//-----------------------------------------------------------------------------
// -- object and list interface methods -- 
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
conduit_node *conduit_node_fetch(conduit_node *cnode,
                                 const char *path);

//-----------------------------------------------------------------------------
conduit_node *conduit_node_append(conduit_node *cnode);

//-----------------------------------------------------------------------------
conduit_node *conduit_node_child(conduit_node *cnode,
                                 size_t idx);

//-----------------------------------------------------------------------------
size_t        conduit_node_number_of_children(conduit_node *cnode);

//-----------------------------------------------------------------------------
size_t        conduit_node_number_of_elements(conduit_node *cnode);

//-----------------------------------------------------------------------------
// -- node info -- 
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
int           conduit_node_is_root(conduit_node *cnode);

//-----------------------------------------------------------------------------
void          conduit_node_print(conduit_node *cnode);
void          conduit_node_print_detailed(conduit_node *cnode);


//-----------------------------------------------------------------------------
// -- leaf set --
//-----------------------------------------------------------------------------

void          conduit_node_set_int32(conduit_node *cnode, 
                                     conduit_int32 value);

//-----------------------------------------------------------------------------
void          conduit_node_set_path_int32(conduit_node *cnode, 
                                          const char *path,
                                          conduit_int32 value);

//-----------------------------------------------------------------------------
void          conduit_node_set_int32_ptr(conduit_node *cnode, 
                                         conduit_int32 *data,
                                         size_t num_elements);

//-----------------------------------------------------------------------------
void          conduit_node_set_external_int32_ptr(conduit_node *cnode, 
                                                  conduit_int32 *data,
                                                  size_t num_elements);

//-----------------------------------------------------------------------------
void          conduit_node_set_float64(conduit_node *cnode, 
                                       conduit_float64 value);

//-----------------------------------------------------------------------------
void          conduit_node_set_int(conduit_node *cnode, 
                                   int value);

//-----------------------------------------------------------------------------
void          conduit_node_set_double(conduit_node *cnode, 
                                      double value);

//-----------------------------------------------------------------------------
// leaf value access
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
int            conduit_node_as_int(conduit_node *cnode);
//-----------------------------------------------------------------------------
int            *conduit_node_as_int_ptr(conduit_node *cnode);

//-----------------------------------------------------------------------------
conduit_int32  conduit_node_as_int32(conduit_node *cnode);
//-----------------------------------------------------------------------------
conduit_int32 *conduit_node_as_int32_ptr(conduit_node *cnode);

//-----------------------------------------------------------------------------
conduit_int32  conduit_node_fetch_path_as_int32(conduit_node *cnode,
                                                const char *path);

//-----------------------------------------------------------------------------
double        conduit_node_as_double(conduit_node *cnode);
//-----------------------------------------------------------------------------
double       *conduit_node_as_double_ptr(conduit_node *cnode);

//-----------------------------------------------------------------------------
conduit_float64 conduit_node_as_float64(conduit_node *cnode);


#ifdef __cplusplus
}
#endif

//-----------------------------------------------------------------------------
// -- end extern C
//-----------------------------------------------------------------------------


#endif