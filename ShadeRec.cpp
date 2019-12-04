#include <ShadeRec.h>

#include <Constants.h>


namespace RTFTGU
{
	// ------------------------------------------------------------------ constructor
	
	ShadeRec::ShadeRec(const Scene& wr)
		: hit_an_object(false),
		hit_point(),
		local_hit_point(),
		normal(),
		ray(),
		depth(0),
		color(black),
		w(wr),
		t(0.0)
	{}
	
	/*
	ShadeRec::ShadeRec(const std::shared_ptr<Scene> scene)
		: hit_an_object(false),
		hit_point(),
		local_hit_point(),
		normal(),
		ray(),
		depth(0),
		color(black),
		w(scene),
		t(0.0)
	{}
	*/
	// ------------------------------------------------------------------copy constructor

		ShadeRec::ShadeRec(const ShadeRec& sr)
		: hit_an_object(sr.hit_an_object),
		hit_point(sr.hit_point),
		local_hit_point(sr.local_hit_point),
		normal(sr.normal),
		ray(sr.ray),
		depth(sr.depth),
		color(sr.color),
		w(sr.w),
		t(sr.t),
		material_ptr(sr.material_ptr)
	{}

	ShadeRec::~ShadeRec(void) 
	{}
}