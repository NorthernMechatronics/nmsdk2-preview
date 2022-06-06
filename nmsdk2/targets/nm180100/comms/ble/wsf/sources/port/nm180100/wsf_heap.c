/*************************************************************************************************/
/*!
 *  \file   wsf_heap.c
 *
 *  \brief  Heap service.
 *
 *  Copyright (c) 2009-2018 Arm Ltd.
 *
 *  Copyright (c) 2019 Packetcraft, Inc.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */
/*************************************************************************************************/

#include "wsf_types.h"
#include "wsf_buf.h"
#include "wsf_assert.h"
#include "wsf_math.h"
#include "wsf_os.h"
#include "wsf_trace.h"
#include "wsf_cs.h"

/**************************************************************************************************
  Global Variables
**************************************************************************************************/
#define WSF_HEAP_SIZE (0x4000)

static uint8_t wsfHeap[WSF_HEAP_SIZE];

static uint8_t *WsfHeapStart = wsfHeap;
static uint32_t WsfHeapSize = WSF_HEAP_SIZE;

/*************************************************************************************************/
/*!
 *  \brief      Reserve heap memory.
 *
 *  \param      size    Number of bytes of heap memory used.
 *
 *  \return     None
 */
/*************************************************************************************************/
void WsfHeapAlloc(uint32_t size)
{
  /* Round up to nearest multiple of 4 for word alignment */
  size = (size + 3) & ~3;

  WsfHeapStart += size;
  WsfHeapSize -= size;
}

/*************************************************************************************************/
/*!
 *  \brief      Get next available heap memory.
 *
 *  \return     Address of the start of heap memory.
 */
/*************************************************************************************************/
void *WsfHeapGetFreeStartAddress(void)
{
  return (void *)WsfHeapStart;
}

/*************************************************************************************************/
/*!
 *  \brief      Get heap available.
 *
 *  \return     Number of bytes of heap memory available.
 */
/*************************************************************************************************/
uint32_t WsfHeapCountAvailable(void)
{
  return WsfHeapSize;
}

/*************************************************************************************************/
/*!
 *  \brief      Get heap used.
 *
 *  \return     Number of bytes of heap memory used.
 */
/*************************************************************************************************/
uint32_t WsfHeapCountUsed(void)
{
  return (WSF_HEAP_SIZE - WsfHeapSize);
}
