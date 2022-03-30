//
//	Dept. Software Convergence, Kyung Hee University
//	Prof. Daeho Lee, nize@khu.ac.kr
//
#include "KhuGleWin.h"
#include <iostream>

class CCollision : public CKhuGleWin
{
public:
	CKhuGleLayer *m_pGameLayer;

	CKhuGleSprite *m_pCircle1;
	CKhuGleSprite *m_pCircle2;
	CKhuGleSprite* m_pCircle3;

	CKhuGleSprite *m_pLine1;
	CKhuGleSprite* m_pLine2;
	CKhuGleSprite* m_pLine3;
	CKhuGleSprite* m_pLine4;

	CKhuGleSprite *m_pNewBlock[200];

	CKhuGleSprite* m_Player_up;
	CKhuGleSprite* m_Player_down;
	CKhuGleSprite* m_Player_right;
	CKhuGleSprite* m_Player_left;

	CCollision(int nW, int nH);
	void Update();

	CKgPoint m_LButtonStart, m_LButtonEnd;
	int m_nLButtonStatus;

	int score;
	int blocks;
	int n;
};

CCollision::CCollision(int nW, int nH) : CKhuGleWin(nW, nH) 
{
	m_nLButtonStatus = 0;

	m_Gravity = CKgVector2D(0., 98.);
	m_AirResistance = CKgVector2D(0.1, 0.1);

	m_pScene = new CKhuGleScene(640, 480, KG_COLOR_24_RGB(100, 100, 150));

	m_pGameLayer = new CKhuGleLayer(600, 420, KG_COLOR_24_RGB(150, 150, 200), CKgPoint(20, 30));

	m_pScene->AddChild(m_pGameLayer);

	m_pCircle1 = new CKhuGleSprite(GP_STYPE_ELLIPSE, GP_CTYPE_DYNAMIC, CKgLine(CKgPoint(30, 300), CKgPoint(60, 330)), 
		KG_COLOR_24_RGB(255, 0, 0), true, 100);
	m_pCircle2 = new CKhuGleSprite(GP_STYPE_ELLIPSE, GP_CTYPE_DYNAMIC, CKgLine(CKgPoint(100, 300), CKgPoint(130, 330)),
		KG_COLOR_24_RGB(255, 0, 0), true, 100);
	m_pCircle3 = new CKhuGleSprite(GP_STYPE_ELLIPSE, GP_CTYPE_DYNAMIC, CKgLine(CKgPoint(100, 300), CKgPoint(130, 330)),
		KG_COLOR_24_RGB(255, 0, 0), true, 100);

	m_pLine1 = new CKhuGleSprite(GP_STYPE_LINE, GP_CTYPE_STATIC, CKgLine(CKgPoint(0, 400), CKgPoint(640, 400)), 
		KG_COLOR_24_RGB(255, 0, 0), false, 10);
	m_pLine2 = new CKhuGleSprite(GP_STYPE_LINE, GP_CTYPE_STATIC, CKgLine(CKgPoint(0, 0), CKgPoint(640, 0)),
		KG_COLOR_24_RGB(255, 0, 0), false, 10);
	m_pLine3 = new CKhuGleSprite(GP_STYPE_LINE, GP_CTYPE_STATIC, CKgLine(CKgPoint(600, 0), CKgPoint(600, 480)),
		KG_COLOR_24_RGB(255, 0, 0), false, 10);
	m_pLine4 = new CKhuGleSprite(GP_STYPE_LINE, GP_CTYPE_STATIC, CKgLine(CKgPoint(0, 0), CKgPoint(0, 480)),
		KG_COLOR_24_RGB(255, 0, 0), false, 10);





	m_Player_up = new CKhuGleSprite(GP_STYPE_LINE, GP_CTYPE_DYNAMIC, CKgLine(CKgPoint(300, 20), CKgPoint(400, 20)),
		KG_COLOR_24_RGB(0, 0, 255), true, 10);
	m_Player_down = new CKhuGleSprite(GP_STYPE_LINE, GP_CTYPE_DYNAMIC, CKgLine(CKgPoint(300, 380), CKgPoint(400, 380)),
		KG_COLOR_24_RGB(0, 0, 255), true, 10);
	m_Player_right = new CKhuGleSprite(GP_STYPE_LINE, GP_CTYPE_DYNAMIC, CKgLine(CKgPoint(20, 300), CKgPoint(20, 400)),
		KG_COLOR_24_RGB(0, 0, 255), true, 10);
	m_Player_left = new CKhuGleSprite(GP_STYPE_LINE, GP_CTYPE_DYNAMIC, CKgLine(CKgPoint(580, 300), CKgPoint(580, 400)),
		KG_COLOR_24_RGB(0, 0, 255), true, 10);

	n = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 16; j++) {
			m_pNewBlock[n] = new CKhuGleSprite(GP_STYPE_RECT, GP_CTYPE_STATIC, CKgLine(CKgPoint(40 * j, 40 * i), CKgPoint(40 + 40 * j, 40 + 40 * i)),
				KG_COLOR_24_RGB(0, 255, 0), false, 100);

			m_pGameLayer->AddChild(m_pNewBlock[n]);
			n++;
		}
	}

	m_pGameLayer->AddChild(m_pCircle1);
	m_pGameLayer->AddChild(m_pCircle2);
	m_pGameLayer->AddChild(m_pCircle3);

	m_pGameLayer->AddChild(m_pLine1);
	m_pGameLayer->AddChild(m_pLine2);
	m_pGameLayer->AddChild(m_pLine3);
	m_pGameLayer->AddChild(m_pLine4);

	m_pGameLayer->AddChild(m_Player_up);
	m_pGameLayer->AddChild(m_Player_down);
	m_pGameLayer->AddChild(m_Player_right);
	m_pGameLayer->AddChild(m_Player_left);

	

	m_pCircle1->m_Velocity = CKgVector2D(100,100);
	m_pCircle2->m_Velocity = CKgVector2D(-100, -100);
	m_pCircle3->m_Velocity = CKgVector2D(100, -100);


	score = 10;
	blocks = 0;
}

void CCollision::Update()
{


	if (m_bKeyPressed['A']) {
		m_Player_up->MoveBy(-1, 0);
		m_Player_down->MoveBy(-1, 0);
	}
	if (m_bKeyPressed['D']) {
		m_Player_up->MoveBy(1, 0);
		m_Player_down->MoveBy(1, 0);
	}
	if (m_bKeyPressed['W']) {
		m_Player_right->MoveBy(0, -1);
		m_Player_left->MoveBy(0, -1);
	}
	if (m_bKeyPressed['S']) {
		m_Player_right->MoveBy(0, 1);
		m_Player_left->MoveBy(0, 1);
	}


	if (blocks > 9 && n<200) {
		blocks = 0;
		std::cout << "new block!" <<'\n';

		for (int k = 0; k < 5; k++) {
			int i = rand() % 6;
			int j = rand() % 11;
			m_pNewBlock[n] = new CKhuGleSprite(GP_STYPE_RECT, GP_CTYPE_STATIC, CKgLine(CKgPoint(40 * j, 40 * i), CKgPoint(40 + 40 * j, 40 + 40 * i)),
				KG_COLOR_24_RGB(0, 255, 0), false, 100);

			m_pGameLayer->AddChild(m_pNewBlock[n]);
			n++;
		}
	}



	for(auto &Layer : m_pScene->m_Children)
	{
		for(auto &Sprite : Layer->m_Children)
		{
			CKhuGleSprite *Ball = (CKhuGleSprite *)Sprite;

			Ball->m_bCollided = false;

			if(Ball->m_nType == GP_STYPE_RECT) continue;
			if(Ball->m_nType != GP_STYPE_ELLIPSE) continue;
			if(Ball->m_nCollisionType != GP_CTYPE_DYNAMIC) continue;


			//Ball->m_Acceleration.x =  Ball->m_Velocity.x ;			
			//Ball->m_Acceleration.y =  Ball->m_Velocity.y ;

			//Ball->m_Velocity.x += Ball->m_Acceleration.x * m_ElapsedTime;
			//Ball->m_Velocity.y += Ball->m_Acceleration.y * m_ElapsedTime;


			if (CKgVector2D::abs(Ball->m_Velocity) < 200) {
				Ball->m_Velocity.x *=  2;
				Ball->m_Velocity.y *=  2;
			}

			Ball->MoveBy(Ball->m_Velocity.x*m_ElapsedTime, Ball->m_Velocity.y*m_ElapsedTime);

			//if(Ball->m_Center.x < 0) Ball->MoveTo(m_nW+Ball->m_Center.x, Ball->m_Center.y);
			//if(Ball->m_Center.x > m_nW) Ball->MoveTo(Ball->m_Center.x-m_nW, Ball->m_Center.y);
			//if(Ball->m_Center.y < 0) Ball->MoveTo(Ball->m_Center.x, m_nH+Ball->m_Center.y);
			//if(Ball->m_Center.y > m_nH) Ball->MoveTo(Ball->m_Center.x, Ball->m_Center.y-m_nH);

	
		}

		std::vector<std::pair<CKhuGleSprite*, CKhuGleSprite*>> CollisionPairs;
		std::vector<CKhuGleSprite*> VirtualBalls;

		for(auto &SpriteA : Layer->m_Children)
		{
			CKhuGleSprite *Ball = (CKhuGleSprite *)SpriteA;
			if(Ball->m_nType != GP_STYPE_ELLIPSE) continue;

			for(auto &SpriteB : Layer->m_Children)
			{
				CKhuGleSprite *Target = (CKhuGleSprite *)SpriteB;

				if(Ball == Target) continue;

				if((((CKhuGleSprite *)Target)->m_nType == GP_STYPE_ELLIPSE))
				{
					CKgVector2D PosVec = Ball->m_Center - Target->m_Center;
					double Overlapped = CKgVector2D::abs(PosVec) - Ball->m_Radius - Target->m_Radius;
					if(Overlapped <= 0)
					{
						CollisionPairs.push_back({Ball, Target});

						if(CKgVector2D::abs(PosVec) == 0)
						{
							if(Ball->m_nCollisionType != GP_CTYPE_STATIC)
								Ball->MoveBy(rand()%3-1, rand()%3-1);
							if(Target->m_nCollisionType != GP_CTYPE_STATIC)
								Target->MoveBy(rand()%3-1, rand()%3-1);
						}
						else
						{
							if(Ball->m_nCollisionType != GP_CTYPE_STATIC)
							{
								if(Target->m_nCollisionType == GP_CTYPE_STATIC)
									Ball->MoveBy(-PosVec.x*Overlapped/CKgVector2D::abs(PosVec), -PosVec.y*Overlapped/CKgVector2D::abs(PosVec));
								else
									Ball->MoveBy(-PosVec.x*Overlapped/CKgVector2D::abs(PosVec)*0.5, -PosVec.y*Overlapped/CKgVector2D::abs(PosVec)*0.5);
							}
							if(Target->m_nCollisionType != GP_CTYPE_STATIC)
							{
								if(Ball->m_nCollisionType == GP_CTYPE_STATIC)
									Target->MoveBy(PosVec.x*Overlapped/CKgVector2D::abs(PosVec), PosVec.y*Overlapped/CKgVector2D::abs(PosVec));
								else
									Target->MoveBy(PosVec.x*Overlapped/CKgVector2D::abs(PosVec)*0.5, PosVec.y*Overlapped/CKgVector2D::abs(PosVec)*0.5);
							}
						}

						Ball->m_bCollided = true;
						Target->m_bCollided = true;
					}
				}

				else if (Target->m_nType == GP_STYPE_RECT) {

					CKgVector2D PosVec = Ball->m_Center - Target->m_Center;
					double Overlapped = CKgVector2D::abs(PosVec) - Ball->m_Radius - Target->m_Radius;
					if (Overlapped <= 0)
					{

						CollisionPairs.push_back({ Ball, Target });

						//if (CKgVector2D::abs(PosVec) == 0)
						//{
						//	if (Ball->m_nCollisionType != GP_CTYPE_STATIC)
						//		Ball->MoveBy(rand() % 3 - 1, rand() % 3 - 1);

						//}
					
							if (Ball->m_nCollisionType != GP_CTYPE_STATIC)
							{
								//if (Target->m_nCollisionType == GP_CTYPE_STATIC)
									Ball->MoveBy((-PosVec.x * Overlapped / CKgVector2D::abs(PosVec)) * m_ElapsedTime, (-PosVec.y * Overlapped / CKgVector2D::abs(PosVec)) * m_ElapsedTime);
							}
							if (Target->m_nCollisionType == GP_CTYPE_STATIC) {

								std::vector<CKhuGleComponent*>::iterator it;

								it = find(m_pGameLayer->m_Children.begin(), m_pGameLayer->m_Children.end(), Target);
								if (it != m_pGameLayer->m_Children.end()) {
									//std::cout << "Element found in myvector: " << ' ' << *it << '\n';
									score += 1;
									blocks++;
									std::cout << "score: " << score  << ' '<< blocks<<'\n';
									m_pGameLayer->m_Children.erase(it);
								}
								else {
									//std::cout << "Element not found in myvector: " << '\n';
								}
							}

						

						
					}
				}
						
				else if(Target->m_nType == GP_STYPE_LINE)
				{
					CKgVector2D LinePos = CKgVector2D(Target->m_lnLine.End.X, Target->m_lnLine.End.Y)
						- CKgVector2D(Target->m_lnLine.Start.X, Target->m_lnLine.Start.Y);

					CKgVector2D LineCirclePos = Ball->m_Center
						- CKgVector2D(Target->m_lnLine.Start.X, Target->m_lnLine.Start.Y);


					double AA = LinePos.Dot(LinePos);

					double ProjectionRate = max(0., min(AA, LinePos.Dot(LineCirclePos))) / AA;

					//CKgVector2D ProjectionPoint = CKgVector2D(Target->m_lnLine.Start) + LinePos*ProjectionRate;
					CKgVector2D ProjectionPoint = CKgVector2D(Target->m_lnLine.Start) + ProjectionRate*LinePos;

					CKgVector2D Normal = Ball->m_Center - ProjectionPoint;

					double Overlapped = CKgVector2D::abs(Normal) - Ball->m_Radius - Target->m_nWidth;
					if(Overlapped <= 0)
					{
						CKhuGleSprite *VirtualBall = new CKhuGleSprite(GP_STYPE_ELLIPSE, GP_CTYPE_STATIC,
							CKgLine((int)(ProjectionPoint.x - Target->m_nWidth/2.), (int)(ProjectionPoint.y - Target->m_nWidth/2.), 
							(int)(ProjectionPoint.x + Target->m_nWidth/2.), (int)(ProjectionPoint.y + Target->m_nWidth/2.)), 
							KG_COLOR_24_RGB(255, 0, 0), false, 100);

						VirtualBall->m_Mass = 1E50;
						VirtualBalls.push_back(VirtualBall);

						CollisionPairs.push_back({Ball, VirtualBall});

						if(CKgVector2D::abs(Normal) == 0)
						{
							if(Ball->m_nCollisionType != GP_CTYPE_STATIC)
								Ball->MoveBy(rand()%3-1, rand()%3-1);
						}
						else
						{
							if(Ball->m_nCollisionType != GP_CTYPE_STATIC)
								Ball->MoveBy(-Normal.x*Overlapped/CKgVector2D::abs(Normal), -Normal.y*Overlapped/CKgVector2D::abs(Normal));
						}

						if (Target->m_nCollisionType == GP_CTYPE_STATIC) {
							score--;
							std::cout << "score: " << score << '\n';
						}

					}
					


				}
			}
		}

		for(auto &Pair : CollisionPairs)
		{
			CKhuGleSprite *BallA = Pair.first;
			CKhuGleSprite *BallB = Pair.second;

			CKgVector2D PosVec = BallB->m_Center - BallA->m_Center;
			double Distance = CKgVector2D::abs(PosVec);
			if(Distance == 0) Distance = 1E-6;
			CKgVector2D Normal = (1./Distance)*PosVec;

			double kx = (BallA->m_Velocity.x - BallB->m_Velocity.x);
			double ky = (BallA->m_Velocity.y - BallB->m_Velocity.y);
			double p = 2.0 * (Normal.x * kx + Normal.y * ky) / (BallA->m_Mass + BallB->m_Mass);

			BallA->m_Velocity.x = BallA->m_Velocity.x - p * BallB->m_Mass * Normal.x;
			BallA->m_Velocity.y = BallA->m_Velocity.y - p * BallB->m_Mass * Normal.y;

			

			BallB->m_Velocity.x = BallB->m_Velocity.x + p * BallA->m_Mass * Normal.x;
			BallB->m_Velocity.y = BallB->m_Velocity.y + p * BallA->m_Mass * Normal.y;
		}

		for(auto &Ball : VirtualBalls) 
			delete Ball;
	}

	m_pScene->Render();
	DrawSceneTextPos("Collision and Physics", CKgPoint(0, 0));



	CKhuGleWin::Update();

}

int main()
{

	CCollision *pCollision = new CCollision(640, 480);

	KhuGleWinInit(pCollision);

	return 0;
}