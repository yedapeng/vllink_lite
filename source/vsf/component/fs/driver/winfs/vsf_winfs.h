/*****************************************************************************
 *   Copyright(C)2009-2019 by VSF Team                                       *
 *                                                                           *
 *  Licensed under the Apache License, Version 2.0 (the "License");          *
 *  you may not use this file except in compliance with the License.         *
 *  You may obtain a copy of the License at                                  *
 *                                                                           *
 *     http://www.apache.org/licenses/LICENSE-2.0                            *
 *                                                                           *
 *  Unless required by applicable law or agreed to in writing, software      *
 *  distributed under the License is distributed on an "AS IS" BASIS,        *
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. *
 *  See the License for the specific language governing permissions and      *
 *  limitations under the License.                                           *
 *                                                                           *
 ****************************************************************************/

#ifndef __VSF_WINFS_H__
#define __VSF_WINFS_H__

/*============================ INCLUDES ======================================*/

#include "../../vsf_fs_cfg.h"

#if VSF_USE_FS == ENABLED && VSF_USE_WINFS == ENABLED

#if     defined(VSF_WINFS_IMPLEMENT)
#   undef VSF_WINFS_IMPLEMENT
#   define __PLOOC_CLASS_IMPLEMENT
#elif   defined(VSF_WINFS_INHERIT)
#   undef VSF_WINFS_INHERIT
#   define __PLOOC_CLASS_INHERIT
#endif

#include "utilities/ooc_class.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================ MACROS ========================================*/
/*============================ MACROFIED FUNCTIONS ===========================*/
/*============================ TYPES =========================================*/

declare_simple_class(vk_winfs_file_t)

enum vk_winfs_file_attr_t {
    VSF_WINFS_FILE_ATTR_ARCHIVE = VSF_FILE_ATTR_EXT,
};
typedef enum vk_fat32_file_attr_t vk_fat32_file_attr_t;

def_simple_class(vk_winfs_file_t) {
    implement(vk_file_t)

    private_member(
        union {
            struct {
                HANDLE hFile;
            } f;
            struct {
                vsf_dlist_t child_list;
            } d;
        };
        uint32_t idx;
        vsf_dlist_node_t child_node;
    )
};

struct vk_winfs_info_t {
    vk_winfs_file_t root;
};
typedef struct vk_winfs_info_t vk_winfs_info_t;

/*============================ GLOBAL VARIABLES ==============================*/

extern const vk_fs_op_t vk_winfs_op;

/*============================ PROTOTYPES ====================================*/

#ifdef __cplusplus
}
#endif

#endif      // VSF_USE_FS && VSF_USE_FATFS
#endif      // __VSF_WINFS_H__
