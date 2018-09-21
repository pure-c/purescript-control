#include <purescript.h>

PURS_FFI_FUNC_2(Control_Extend_arrayExtend, f, _xs, {
	int i;
	const purs_vec_t * innerCopy;
	const purs_any_t * tmp;
	const purs_vec_t * xs = purs_any_get_array(_xs);
	purs_vec_t * copy = (purs_vec_t *) purs_vec_copy(xs);
	purs_vec_foreach(copy, tmp, i) {
		innerCopy = purs_vec_slice(xs, i);
		copy->data[i] = purs_any_app(f, PURS_ANY_ARRAY_NEW(innerCopy));
	}
	return PURS_ANY_ARRAY_NEW((const purs_vec_t *) copy);
})
