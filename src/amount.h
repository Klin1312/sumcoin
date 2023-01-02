// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2018 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_AMOUNT_H
#define BITCOIN_AMOUNT_H

#include <stdint.h>
#include <string>

/** Amount in satoshis (Can be negative) */
typedef int64_t CAmount;

static const CAmount COIN = 1000000;
static const CAmount CENT = 10000;

static const CAmount MIN_TX_FEE_PREV7 = CENT;
static const CAmount MIN_TX_FEE = CENT / 10;
static const CAmount PERKB_TX_FEE = CENT;
static const CAmount MIN_TXOUT_AMOUNT = CENT;
static const CAmount MAX_MINT_PROOF_OF_WORK = 200000; // 200,000 for the initial PoW;
static const CAmount MAX_MINT_PROOF_OF_WORK_V10 = 200000; // 200,000 for the initial PoW;
static const std::string CURRENCY_UNIT = "SUM";

/** No amount larger than this (in satoshi) is valid.
 *
 * Note that this constant is *not* the total money supply, which in Bitcoin
 * currently happens to be less than 21,000,000 BTC for various reasons, but
 * rather a sanity check. As this sanity check is used by consensus-critical
 * validation code, the exact value of the MAX_MONEY constant is consensus
 * critical; in unusual circumstances like a(nother) overflow bug that allowed
 * for the creation of coins out of thin air modification could lead to a fork.
 * */
static const CAmount MAX_MONEY = 200000000 * COIN;
static const CAmount PROOF_OF_WORK_BLOCKS = 1000; // Block height of the last proof of work block

inline bool MoneyRange(const CAmount& nValue) { return (nValue >= 0 && nValue <= MAX_MONEY); }

#endif //  BITCOIN_AMOUNT_H
