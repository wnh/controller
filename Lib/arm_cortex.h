/* Copyright (C) 2018 by Rowan Decker
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#pragma once

/*
 * Exception type    Position       Priority       Description
 * --------------    ------------   --------       ------------------------------------
 * Reset               1             –3 (highest)  Invoked on power up and warm reset. On first instruction,
 *                                                 drops to lowest priority (Thread mode). This is asynchronous
 * Non-maskable Int    2             –2            Cannot be stopped or pre-empted by any exception but reset.
 *                                                 This is asynchronous.
 * Hard Fault          3             –1            All classes of Fault, when the fault cannot activate because of
 *                                                 priority or the Configurable Fault handler has been disabled.
 *                                                 This is synchronous.
 * Memory Management   4             Configurable  Memory Protection Unit (MPU) mismatch, including access
 *                                                 violation and no match. This is synchronous. This is used
 *                                                 even if the MPU is disabled or not present, to support the
 *                                                 Executable Never (XN) regions of the default memory map.
 * Bus Fault           5             Configurable  Pre-fetch fault, memory access fault, and other
 *                                                 address/memory related. This is synchronous when precise
 *                                                 and asynchronous when imprecise.
 * Usage Fault         6             Configurable  Usage fault, such as Undefined instruction executed or illegal
 *                                                 state transition attempt. This is synchronous.
 *   -                 7-10            -           Reserved
 * SVCall              11            Configurable  System service call with SVC instruction. This is
 *                                                 synchronous.
 * Debug Monitor       12            Configurable  Debug monitor, when not halting. This is synchronous, but
 *                                                 only active when enabled. It does not activate if lower priority
 *                                                 than the current activation.
 *   -                 13              -           Reserved
 * PendSV              14            Configurable  Pendable request for system service. This is asynchronous
 *                                                 and only pended by software.
 * SysTick             15            Configurable  System tick timer has fired. This is asynchronous.
 *
 * External Interrupt  16 and above  Configurable  Asserted from outside the core, INTISR[239:0], and fed
 *                                                 through the NVIC (prioritized). These are all asynchronous.
 */
typedef enum {
	IRQ_Reset = 1,
	IRQ_NMI = 2,
	IRQ_HardFault = 3,
	IRQ_MemoryManagement = 4,
	IRQ_BusFault = 5,
	IRQ_UsageFault = 6,
	IRQ_SVCall = 11,
	IRQ_PendSV = 14,
	IRQ_SysTick = 15,
	IRQ_External = 16
} Cortex_IRQ;
