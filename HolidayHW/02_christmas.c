#include <stdio.h>

typedef struct tree{
	float height, price;
} tree_t;

float ratio(tree_t tree);
tree_t best_price_for_height(tree_t *trees);

int main(){
	tree_t shop[] = {{2, 7},{1.6, 10}, {3, 12}, {1.8, 11.1}, {2.9, 11.7}, 
			{0.9, 4}, {1.2, 6}, {3.6, 17.4}, {2.4, 8}, {0.3, 1.4}};

	tree_t best = best_price_for_height(shop);

	printf("Best tree height: %.2f price: %.2f h/p ratio: %.2f\n",
 best.height, best.price, ratio(best));

	return 0;
}

float ratio(tree_t tree){
	return tree.price/(tree.height * 100);
}

tree_t best_price_for_height(tree_t *trees){
	tree_t best_ratio_tree = trees[0];
	for(int i = 1; i < 10; ++i)
		if(ratio(best_ratio_tree) > ratio(trees[i]))
			best_ratio_tree = trees[i];
	return best_ratio_tree;
}
