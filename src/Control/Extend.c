#include <purescript.h>

PURS_FFI_FUNC_2(Control_Extend_arrayExtend, f, _xs) {
	int i;
	purs_any_t tmp;
	const purs_vec_t * inner_copy;

	const purs_vec_t * xs = purs_any_force_array(_xs);
	purs_vec_t * copy = (purs_vec_t *) purs_vec_copy(xs);
	purs_vec_foreach(copy, tmp, i) {
		inner_copy = purs_vec_splice(xs, i, xs->length - i);
		copy->data[i] = purs_any_app(f, purs_any_array(inner_copy));
		PURS_RC_RELEASE(inner_copy);
	}
	PURS_RC_RELEASE(xs);

	return purs_any_array(copy);
}
