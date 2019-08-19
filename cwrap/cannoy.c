#include "cannoy.h"
#include "../src/kissrandom.h"
#include "../src/annoylib.h"


hannoy NewAnnoyIndexEuclidean(int dimession){
	AnnoyIndex<int, double, Euclidean, Kiss32Random> *t = new AnnoyIndex<int, double, Euclidean, Kiss32Random>(dimession);
	return (hannoy)t;
}

void DestroyAnnoyIndex(hannoy h){
	AnnoyIndex<int, double, Euclidean, Kiss32Random> *t = (AnnoyIndex<int, double, Euclidean, Kiss32Random> *)h;
	t->unload();
	delete t;
}

void AnnoyAddItem(hannoy h, int id, double *vector){
	AnnoyIndex<int, double, Euclidean, Kiss32Random> *t = (AnnoyIndex<int, double, Euclidean, Kiss32Random> *)h;
	t->add_item(id, vector);
	return;
}

void AnnoyGetItem(hannoy h, int id, double *vector){
	AnnoyIndex<int, double, Euclidean, Kiss32Random> *t = (AnnoyIndex<int, double, Euclidean, Kiss32Random> *)h;
	t->get_item(id, vector);
	return;
}

int AnnoyGetNItems(hannoy h){
	AnnoyIndex<int, double, Euclidean, Kiss32Random> *t = (AnnoyIndex<int, double, Euclidean, Kiss32Random> *)h;
	return t->get_n_items();
}

void AnnoyBuild(hannoy h, int nTree){
	AnnoyIndex<int, double, Euclidean, Kiss32Random> *t = (AnnoyIndex<int, double, Euclidean, Kiss32Random> *)h;
	t->build(nTree);
}

int AnnoySave(hannoy h, char *fname){
	AnnoyIndex<int, double, Euclidean, Kiss32Random> *t = (AnnoyIndex<int, double, Euclidean, Kiss32Random> *)h;
	return (int)t->save(fname);
}

int AnnoyLoad(hannoy h, char *fname){
	AnnoyIndex<int, double, Euclidean, Kiss32Random> *t = (AnnoyIndex<int, double, Euclidean, Kiss32Random> *)h;
	return (int)t->load(fname);
}

double AnnoyGetDistance(hannoy h, int i, int j){
	AnnoyIndex<int, double, Euclidean, Kiss32Random> *t = (AnnoyIndex<int, double, Euclidean, Kiss32Random> *)h;
	t->get_distance(i,j);
}

void AnnoyGetNnsByItem(hannoy h, int id, size_t n, int *idary, double *disary)
{
	AnnoyIndex<int, double, Euclidean, Kiss32Random> *t = (AnnoyIndex<int, double, Euclidean, Kiss32Random> *)h;
	std::vector<int> idvec;
	std::vector<double> disvec;
	//printf("AnnoyGetnnsByItem: before get_nns_by_item\n"); fflush(stdout);
	t->get_nns_by_item(id, n, (size_t)-1, &idvec, &disvec);
	//printf("AnnoyGetnnsByItem: after get_nns_by_item\n"); fflush(stdout);
	for(std::vector<int>::iterator id = idvec.begin(); id!=idvec.end(); ++id){
		*idary++ = *id;
	}
	for(std::vector<double>::iterator dis = disvec.begin(); dis!=disvec.end(); ++dis){
		*disary++ = *dis;
	}
}


void AnnoyGetNnsByVector(hannoy h, const double *given, size_t n, int *idary, double *disary){
	AnnoyIndex<int, double, Euclidean, Kiss32Random> *t = (AnnoyIndex<int, double, Euclidean, Kiss32Random> *)h;
	std::vector<int> idvec;
	std::vector<double> disvec;
	//printf("AnnoyGetnnsByVector: before get_nns_by_vector: %p\n", t); fflush(stdout);
	t->get_nns_by_vector(given, n, (size_t)-1, &idvec, &disvec);
	//printf("AnnoyGetnnsByVector: after get_nns_by_vector\n"); fflush(stdout);
	for(std::vector<int>::iterator id = idvec.begin(); id!=idvec.end(); ++id){
		*idary++ = *id;
	}
	for(std::vector<double>::iterator dis = disvec.begin(); dis!=disvec.end(); ++dis){
		*disary++ = *dis;
	}
}

