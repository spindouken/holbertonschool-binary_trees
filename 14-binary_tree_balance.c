#include "binary_trees.h"

/**
 * heightFinder - find height for a node
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height or 0 if tree is NULL
 */

int heightFinder(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);
	left = heightFinder(tree->left);
	right = heightFinder(tree->right);
	if (left >= right)
		return (1 + left);
	else
		return (1 + right);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: the balance factor
 * or 0 if tree is NULL
 */

int binary_tree_balance(const binary_tree_t *tree)
{

	if (tree == NULL)
		return (0);
	return (heightFinder(tree->left) - heightFinder(tree->right));
}
