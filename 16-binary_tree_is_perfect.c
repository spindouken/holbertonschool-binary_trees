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

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 0 if tree is NULL
 * return 0 if the tree is not perfect
 * (the heights of the left and right subtrees are not equal)
 * returns 1 if tree is perfect
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (binary_tree_balance(tree) != 0)
		return (0);
	if ((tree->left) && (tree->right))
		return (binary_tree_is_perfect(tree->left) &&
				binary_tree_is_perfect(tree->right));
	return (0);
}
