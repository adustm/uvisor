/*
 * Copyright (c) 2013-2016, ARM Limited, All Rights Reserved
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef __VMPU_UNPRIV_ACCESS_H__
#define __VMPU_UNPRIV_ACCESS_H__

#include "api/inc/uvisor_exports.h"
#include <stdint.h>

/** Write an 8-bit value to an address as if in unprivileged mode.
 *
 * This function can be used even if the MPU is disabled, but the architectural
 * restrictions on privileged-only registers still apply.
 *
 * @warning: Upon failure this function triggers a fault (MemManage if enabled,
 *
 * @param addr[in]  Address to write to.
 * @param data[in]  8-bit data to write.
 */
static UVISOR_FORCEINLINE void vmpu_unpriv_uint8_write(uint32_t addr, uint8_t data)
{
    asm volatile (
        "strbt %[data], [%[addr]]\n"
        :: [addr] "r" (addr), [data] "r" (data)
    );
}

/** Write a 16-bit value to an address as if in unprivileged mode.
 *
 * This function can be used even if the MPU is disabled, but the architectural
 * restrictions on privileged-only registers still apply.
 *
 * @warning: Upon failure this function triggers a fault (MemManage if enabled,
 * otherwise HardFault).
 *
 * @param addr[in]  Address to write to.
 * @param data[in]  16-bit data to write.
 */
static UVISOR_FORCEINLINE void vmpu_unpriv_uint16_write(uint32_t addr, uint16_t data)
{
    asm volatile (
        "strht %[data], [%[addr]]\n"
        :: [addr] "r" (addr), [data] "r" (data)
    );
}

/** Write a 32-bit value to an address as if in unprivileged mode.
 *
 * This function can be used even if the MPU is disabled, but the architectural
 * restrictions on privileged-only registers still apply.
 *
 * @warning: Upon failure this function triggers a fault (MemManage if enabled,
 * otherwise HardFault).
 *
 * @param addr[in]  Address to write to.
 * @param data[in]  32-bit data to write.
 */
static UVISOR_FORCEINLINE void vmpu_unpriv_uint32_write(uint32_t addr, uint32_t data)
{
    asm volatile (
        "strt %[data], [%[addr]]\n"
        :: [addr] "r" (addr), [data] "r" (data));
}

/** Read an 8-bit value from an address as if in unprivileged mode.
 *
 * This function can be used even if the MPU is disabled, but the architectural
 * restrictions on privileged-only registers still apply.
 *
 * @warning: Upon failure this function triggers a fault (MemManage if enabled,
 * otherwise HardFault).
 *
 * @param addr[in]  Address to read from.
 * @returns the 8-bit value read from the address.
 */
static UVISOR_FORCEINLINE uint8_t vmpu_unpriv_uint8_read(uint32_t addr)
{
    uint8_t res;
    asm volatile (
        "ldrbt %[res], [%[addr]]\n"
        : [res] "=r" (res)
        : [addr] "r" (addr));
    return res;
}

/** Read a 16-bit value from an address as if in unprivileged mode.
 *
 * This function can be used even if the MPU is disabled, but the architectural
 * restrictions on privileged-only registers still apply.
 *
 * @warning: Upon failure this function triggers a fault (MemManage if enabled,
 * otherwise HardFault).
 *
 * @param addr[in]  Address to read from.
 * @returns the 16-bit value read from the address.
 */
static UVISOR_FORCEINLINE uint16_t vmpu_unpriv_uint16_read(uint32_t addr)
{
    uint16_t res;
    asm volatile (
        "ldrht %[res], [%[addr]]\n"
        : [res] "=r" (res)
        : [addr] "r" (addr));
    return res;
}

/** Read a 32-bit value from an address as if in unprivileged mode.
 *
 * This function can be used even if the MPU is disabled, but the architectural
 * restrictions on privileged-only registers still apply.
 *
 * @warning: Upon failure this function triggers a fault (MemManage if enabled,
 * otherwise HardFault).
 *
 * @param addr[in]  Address to read from.
 * @returns the 32-bit value read from the address.
 */
static UVISOR_FORCEINLINE uint32_t vmpu_unpriv_uint32_read(uint32_t addr)
{
    uint32_t res;
    asm volatile (
        "ldrt %[res], [%[addr]]\n"
        : [res] "=r" (res)
        : [addr] "r" (addr)
    );
    return res;
}

#endif /* __VMPU_UNPRIV_ACCESS_H__ */
