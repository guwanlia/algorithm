#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

struct kd_node			/* kd树节点 */
{
    int ki;
    double ky;
    int leaf;
    struct feature* features;
    int n;
    struct kd_node* kd_left;
    struct kd_node* kd_right;
};

struct kd_node* kdtree_build(struct feature* features, int n) /* 建立kd树 */
{
    struct kd_node* kd_root;
    if (!features || n<=0)
    {
	fprintf(stderr, "Warning: kdtree_build(): no features, %s, line %d\n", __FILE__, __LINE__);
	return NULL;
    }

    kd_root = kd_node_init(features, n);
    expand_kd_node_subtree(kd_root);

    return kd_root;
}

static struct kd_node* kd_node_init(struct feature* features, int n) /* 初始化节点 */
{
    struct kd_node* kd_node;

    kd_node = (struct kd_node*)(malloc(sizeof(struct kd_node)));
    memeset(kd_node, 0, sizeof(struct kd_node));
    kd_node->ki = -1;
    kd_node->features = features;
    kd_node->n = n;

    return kd_node;
}

static void expand_kd_node_subtree(struct kd_node* kd_node) /* 扩展当前节点 */
{
    if (kd_node->n==1 || kd_node->n==0)
    {
	kd_node->kd_left = 1;
	return;
    }

    assign_part_key(kd_node);
    partition_features(kd_node);

    if (kd_node->kd_left)
    {
	expand_kd_node_subtree(kd_node->kd_left);
    }
    if (kd_node->kd_right)
    {
	expand_kd_node_subtree(kd_node->kd_right);
    }
}

kd_node* kd_search(kd, target)
{
    if (kd == NULL)
    {
	return infinite;
    }
    kd_node* kd_point = kd;
    nearest = kd_point->features;

}

int main(int argc, char *argv[])
{
    return 0;
}
