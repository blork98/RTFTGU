#ifndef MATRIX_H_
#define MATRIX_H_

namespace RTFTGU
{
	class Matrix 
	{

		public:

			double	m[4][4];								// elements

			Matrix(void);									// default constructor
			Matrix(const Matrix& mat);						// copy constructor
			~Matrix(void);									// destructor

			Matrix& operator= (const Matrix& rhs);			// assignment operator
			Matrix 	operator* (const Matrix& mat) const;	// multiplication of two matrices
			Matrix 	operator/ (const double d);				// divsion by a double

			void	set_identity(void);						// set to the identity matrix
			
	};
}

#endif