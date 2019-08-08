#ifndef CANNOY_H
#define CANNOY_H

#include "stdlib.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void * hannoy;

hannoy NewAnnoyIndexEuclidean(int dimession);

void DestroyAnnoyIndex(hannoy h);

void AnnoyAddItem(hannoy h, int id, double *vector);

void AnnoyGetItem(hannoy h, int id, double *vector);

int AnnoyGetNItems(hannoy h);

void AnnoyBuild(hannoy h, int nTree);

int AnnoySave(hannoy h, char *fname);

int AnnoyLoad(hannoy h, char *fname);

double AnnoyGetDistance(hannoy h, int i, int j);

void AnnoyGetNnsByItem(hannoy h, int id, size_t n, int *idary, double *disary);

void AnnoyGetNnsByVector(hannoy h, const double *given, size_t n, int *idary, double *disary);

#ifdef __cplusplus
}
#endif
#endif // CANNOY_H
