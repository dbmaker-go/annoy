#include "cannoy.h"
#include <stdio.h>

int main(){

	hannoy idx1;
	double vec[2], d;
	int idary[5], i,n;
	double disary[5];

  idx1 = NewAnnoyIndexEuclidean(2);
  printf("new annoy index ok\n");
  
	vec[0] = 1;
	vec[1] = 1;
	AnnoyAddItem(idx1, 0, vec);
	
	vec[0] = 2;
	vec[1] = 2;
	AnnoyAddItem(idx1, 1, vec);
	
	vec[0] = 2;
	vec[1] = -2;
	AnnoyAddItem(idx1, 2, vec);
	
	vec[0] = -2;
	vec[1] = -1;
	AnnoyAddItem(idx1, 3, vec);

  printf("add 4 items\n");

	AnnoyBuild(idx1, 1);

  printf("build index with 1 tree\n");

  n = AnnoyGetNItems(idx1);
  printf("idx1 has %d items\n", n);
  
  for (i=0; i<n; i++){
    AnnoyGetItem(idx1, i, vec);
    printf("item[%d] = [%f,%f]\n", i, vec[0], vec[1]);
  }
	
	d = AnnoyGetDistance(idx1, 2,1);
	printf("dis (2,2) to (2,-2): %f\n", d);
	
	vec[0] = 1;
	vec[1] = -1;
	AnnoyGetNnsByVector(idx1, vec, 3, idary, disary);
	
	printf("nearest to (1,-1):\n");// [%d,%d], [%f, %f]\n", idary[0], idary[1], disary[0], disary[1]);
	for (i=0; i<3; i++){
		printf("  %d: %f\n", idary[i], disary[i]);
	}
	
	AnnoyGetNnsByItem(idx1, 0, 3, idary, disary);
	
	printf("nearest to (1,1):\n");// [%d,%d], [%f, %f]\n", idary[0], idary[1], disary[0], disary[1]);
	for (i=0; i<3; i++){
		printf("  %d: %f\n", idary[i], disary[i]);
	}
	
	AnnoySave(idx1, "idx1.tree");
	
	DestroyAnnoyIndex(idx1);
	
	idx1 = NewAnnoyIndexEuclidean(2);
	AnnoyLoad(idx1, "idx1.tree");
	AnnoyGetNnsByItem(idx1, 1, 3, idary, disary);
	
	printf("nearest to (2,2):\n");// [%d,%d], [%f, %f]\n", idary[0], idary[1], disary[0], disary[1]);
	for (i=0; i<3; i++){
		printf("  %d: %f\n", idary[i], disary[i]);
	}
	
	DestroyAnnoyIndex(idx1);
	
	return 0;
}

