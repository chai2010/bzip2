// Copyright 2015 <chaishushan{AT}gmail.com>. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#include <bzlib.h>

int bz2compress(
	bz_stream *s, int action,
	char *in, unsigned *inlen,
	char *out, unsigned *outlen
) {
	s->next_in = in;
	s->avail_in = *inlen;
	s->next_out = out;
	s->avail_out = *outlen;
	int r = BZ2_bzCompress(s, action); // warning?
	*inlen -= s->avail_in;
	*outlen -= s->avail_out;
	s->next_in = s->next_out = NULL;
	return r;
}

