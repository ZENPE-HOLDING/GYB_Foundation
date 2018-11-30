/**********************************************************************
 * Copyright (c) 2014, 2018 Gregory Maxwell                          *
 * Distributed under the MIT software license, see the accompanying   *
 * file COPYING or http://www.opensource.org/licenses/mit-license.php.*
 **********************************************************************/


#ifndef _SECP256K1_BORROMEAN_H_
#define _SECP256K1_BORROMEAN_H_

#include "scalar.h"
#include "field.h"
#include "group.h"
#include "ecmult.h"
#include "ecmult_gen.h"

int secp256k1_borromean_verify(const secp256k1_ecmult_context_t* ecmult_ctx, secp256k1_scalar_t *evalues, const unsigned char *e0, const secp256k1_scalar_t *s,
 const secp256k1_gej_t *pubs, const int *rsizes, int nrings, const unsigned char *m, int mlen);

int secp256k1_borromean_sign(const secp256k1_ecmult_context_t* ecmult_ctx, const secp256k1_ecmult_gen_context_t *ecmult_gen_ctx,
 unsigned char *e0, secp256k1_scalar_t *s, const secp256k1_gej_t *pubs, const secp256k1_scalar_t *k, const secp256k1_scalar_t *sec,
 const int *rsizes, const int *secidx, int nrings, const unsigned char *m, int mlen);

#endif