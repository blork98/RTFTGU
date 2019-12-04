#include <GlossySpecularBRDF.h>

namespace RTFTGU
{
	GlossySpecularBRDF::GlossySpecularBRDF()
		:ks(0.0),
		cs(1.0)
	{}

	GlossySpecularBRDF::~GlossySpecularBRDF()
	{}

	RGBColor
	GlossySpecularBRDF::f(const ShadeRec& sr, const Vector3D& wo, const Vector3D& wi) const
	{
		RGBColor 	L;
		float 		ndotwi = sr.normal * wi;
		Vector3D 	r(-wi + 2.0 * sr.normal * ndotwi); // mirror reflection direction
		float 		rdotwo = r * wo;

		if (rdotwo > 0.0)
			L = ks * cs * pow(rdotwo, exp);

		return (L);
	}

	RGBColor
	GlossySpecularBRDF::f_blinn(const ShadeRec& sr, const Vector3D& wo, const Vector3D& wi) const
	{
		RGBColor 	L;
		Vector3D    h(wi + wo);
		h = h / h.length();
		float 		ndoth = sr.normal * h;

		if (ndoth > 0.0)
			L = ks * cs * pow(ndoth, exp);

		return (L);
	}

	RGBColor
	GlossySpecularBRDF::rho(const ShadeRec& sr, const Vector3D& wo) const
	{
		return (black);
	}

	void
	GlossySpecularBRDF::set_ks(const float k)
	{
		ks = k;
	}

	void
	GlossySpecularBRDF::set_exp(const float e)
	{
		exp = e;
	}

	void
	GlossySpecularBRDF::set_cs(const RGBColor& c)
	{
		cs = c;
	}

	void
	GlossySpecularBRDF::set_cs(const float r, const float g, const float b)
	{
		cs.r = r; cs.g = g; cs.b = b;
	}

	void
	GlossySpecularBRDF::set_cs(const float c)
	{
		cs.r = c; cs.g = c; cs.b = c;
	}
}