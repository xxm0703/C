#include <stdio.h>

typedef struct tree{
	float height, price;
} tree_t;


float ratio(tree_t tree){
	return tree.height/tree.price;
}

tree_t best_price_for_height(tree_t *trees){
	tree_t best_ratio_tree = trees[0];
	for(int i = 1; i < 10; ++i)
		if(ratio(best_ratio_tree) > ratio(trees[i]))
			best_ratio_tree = trees[i];
	return best_ratio_tree;
}
