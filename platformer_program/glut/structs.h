typedef struct point {
	float x;
	float y;
	float z;
} point;

typedef struct tsr {
	point t; /* translation */
	point s; /* scale */
	point r; /* rotation */
	point hely;
} tsr;

typedef struct cube_s {
	tsr tsr;
} cube_s;



typedef struct tsr2 {
	point t; /* translation */
	point s; /* scale */
	point r; /* rotation */
	point hely;
	point tobbi;
} tsr2;

typedef struct platform_s {
	tsr2 tsr;
} platform_s;



class molekula
{
public:
	bool van;	//van-e molekula az adott helyen
	bool ter;	//térrel terhelt-e a molekula az adott helyen
	double dipA, dipB, dip;		//dipólok
	double qeA, qeB, qp1A, qp1B, qp2A, qp2B;	//új egyenletekhez (equations.docx)
};
