#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <openssl/sha.h> necessary library for hash algorithm like SHA-256

#define HASH_SIZE 256 //SHA256_DIGEST_LENGTH

typedef struct Node
{
	unsigned char	hash[HASH_SIZE];
	struct Node 	*left;
	struct Node 	*right;
}Node;

Node	*create_leaft_node(const unsigned char *data, size_t data_size)
{
	Node	*leaf;

	leaf = (Node *)malloc(sizeof(Node));
	if (!leaf)
		return (NULL);
	memcpy(leaf->hash, data, data_size);
	leaf->left = NULL;
	leaf->right = NULL;
	return (leaf);
}

Node	*create_parent_node(Node *left, Node *right)
{
	Node	*parent;

	parent = (Node *)malloc(sizeof(Node));
	if (!parent)
		return (NULL);

	// SHA256_CTX ctx;
	// SHA256_Init(&ctx);
    // SHA256_Update(&ctx, left->hash, HASH_SIZE);
    // SHA256_Update(&ctx, right->hash, HASH_SIZE);
    // SHA256_Final(parent->hash, &ctx);

	parent->left = left;
	parent->right = right;
	return (parent);
}

Node	*build_merkle_tree(const unsigned char **data, size_t data_size)
{
	Node	**nodes;
	Node	**parents;
	size_t	level_size;
	size_t	parent_size;

	nodes = (Node **)malloc(sizeof(Node *) * data_size);
	if (!nodes)
		return (NULL);

	for (size_t i = 0; i < data_size; i++)
		nodes[i] = create_leaf_node(data[i], HASH_SIZE);

	level_size = data_size;
	while (level_size > 1)
	{
		parent_size = (level_size + 1) / 2;
		parents = (Node **)malloc(sizeof(Node *) * parent_size);
		if (!parents)
			return (NULL);
		for (size_t i = 0; i < parent_size; i++)
		{
			if (i * 2 + 1 < level_size)
				parents[i] = create_parent_node(nodes[i * 2], nodes[i * 2 + 1]);
			else
				parents[i] = create_parent_node(nodes[i * 2], nodes[i * 2]);
		}
		free(nodes);
		nodes = parents;
		level_size = parent_size;
	}

	Node	*root = nodes[0];

	free(nodes);
	return (root);
}


// void print_hex(const unsigned char* data, size_t data_size) {
// 	for (size_t i = 0; i < data_size; i++) {
// 		printf("%02x", data[i]);
// 	}
// 	printf("\n");
// }

// int main() {
// 	const unsigned char* data[] = {
// 		(const unsigned char*)"transaction1",
// 		(const unsigned char*)"transaction2",
// 		(const unsigned char*)"transaction3",
// 		(const unsigned char*)"transaction4"
// 	};
// 	size_t data_size = sizeof(data) / sizeof(data[0]);

// 	Node* root = build_merkle_tree(data, data_size);

// 	printf("Root Hash: ");
// 	print_hex(root->hash, HASH_SIZE);

// 	return 0;
// }