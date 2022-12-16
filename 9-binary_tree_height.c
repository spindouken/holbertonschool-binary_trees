#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: the number of height or 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t rightTreeHeight, leftTreeHeight;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);
	leftTreeHeight = binary_tree_height(tree->left);
	rightTreeHeight = binary_tree_height(tree->right);
	return ((leftTreeHeight > rightTreeHeight ?
	 leftTreeHeight : rightTreeHeight) + 1);
}
