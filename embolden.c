#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <stdlib.h>
#include <assert.h>
#include <dlfcn.h>
#include <ft2build.h>
#include <freetype/freetype.h>
#include <freetype/ftoutln.h>

FT_EXPORT( FT_Error )
FT_Render_Glyph( FT_GlyphSlot    slot,
	   FT_Render_Mode  render_mode )
{
	static typeof(FT_Render_Glyph) *next;
	static FT_Pos bolder;
	if (next == NULL) {
		next = dlsym(RTLD_NEXT, __func__);
		assert(next);
		const char *s = getenv("EMBOLDEN");
		if (s)
			bolder = atoi(s);
	}
	if (bolder > 0 && slot->format == FT_GLYPH_FORMAT_OUTLINE)
		FT_Outline_Embolden(&slot->outline, bolder);
	return next(slot, render_mode);
}
