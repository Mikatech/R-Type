#include "test.h"

/* This module was badly broken due to previously ignoring
 * the pattern offset field. */

TEST(test_loader_coco_patalign)
{
	xmp_context opaque;
	struct xmp_module_info info;
	FILE *f;
	int ret;

	f = fopen("data/format_coco_patalign.data", "r");

	opaque = xmp_create_context();
	ret = xmp_load_module(opaque, "data/m/Millenium2.Coconizer");
	fail_unless(ret == 0, "module load");

	xmp_get_module_info(opaque, &info);

	ret = compare_module(info.mod, f);
	fail_unless(ret == 0, "format not correctly loaded");

	xmp_release_module(opaque);
	xmp_free_context(opaque);
}
END_TEST
