/* bzflag
 * Copyright (c) 1993 - 2002 Tim Riker
 *
 * This package is free software;  you can redistribute it and/or
 * modify it under the terms of the license found in the file
 * named LICENSE that should have accompanied this file.
 *
 * THIS PACKAGE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

#ifndef BZF_BOUNDING_BOX_H
#define BZF_BOUNDING_BOX_H

class Matrix;

class BoundingBox {
public:
	BoundingBox();
	BoundingBox(const float* minXYZ, const float* maxXYZ);
	BoundingBox(float xMin, float yMin, float zMin,
							float xMax, float yMax, float zMax);
	BoundingBox(const BoundingBox&);
	~BoundingBox();

	BoundingBox&		operator=(const BoundingBox&);

	// set a box's axis-aligned extents
	void				set(const float* minXYZ, const float* maxXYZ);
	void				set(float xMin, float yMin, float zMin,
							float xMax, float yMax, float zMax);

	// transform a bounding box
	void				transform(const Matrix&);

	// get the box's axis-aligned extents
	void				get(float* minXYZ, float* maxXYZ) const;

private:
	// p is: center, +x face center, +y face center, +z face center
	float				p[4][3];
};

#endif
