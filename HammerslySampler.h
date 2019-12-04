#ifndef HAMMERSLEY_SAMPLER_H_
#define HAMMERSLEY_SAMPLER_H_

#include <Sampler.h>

namespace RTFTGU
{
	class Hammersley : public Sampler
	{
		public:
			Hammersley();
			Hammersley(const int num);
			~Hammersley();

			virtual void generate_samples(void);

		private:
			double phi(int j) const;
	};
}

#endif