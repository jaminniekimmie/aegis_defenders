#pragma once
#include "gameNode.h"

//�Ѿ� ����ü
struct tagBullet
{
	image* bulletImage;
	RECT rc;
	BYTE alpha;
	float x, y;
	float fireX, fireY;
	float speed;
	float angle;
	float gravity;
	float radius;
	bool fire;
	int count;
};

//=============================================================
//	## bullet ## (�����Ѿ� - ������� ����� �ȴ�)
//=============================================================
class bullet : public gameNode
{
private:
	//�Ѿ� ����ü�� ���� ����, �ݺ���
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;
	vector<tagBullet> _vParticle;
	vector<tagBullet>::iterator _viParticle;
	vector<tagBullet> _vMagazine;
	vector<tagBullet>::iterator _viMagazine;

private:
	const char* _imageName;		//�Ѿ� �̹��� �̸�(Ű��)
	float _range;			//�Ѿ� ��Ÿ�
	int _bulletMax;			//�Ѿ� �ִ밹��
	int a;
	bool _isFrameImg;		//�̹����Ŵ����� ��� �ִ� �̹����� �������� �ֳ� ����?

public:
	HRESULT init(const char* imageName, int bulletMax, float range);
	void release(void);
	void update(void);
	void render(void);

	//�Ѿ˹߻�
	void fire(float x, float y, float angle, float speed);
	//�Ѿ˹���
	void move();
	
	void collision();

	//�Ѿ˻���
	void removeBullet(int index);

	//�Ѿ˺��� ��������
	vector<tagBullet> getVBullet() { return _vBullet; }
	vector<tagBullet>::iterator getViBullet() { return _viBullet; }
	vector<tagBullet> getVParticle() { return _vParticle; }
	vector<tagBullet>::iterator getViParticle() { return _viParticle; }
	vector<tagBullet> getVMagazine() { return _vMagazine; }
	vector<tagBullet>::iterator getViMagazine() { return _viMagazine; }

	bullet() {}
	~bullet() {}
};

//=============================================================
//	## missile ## (missile[0] -> �迭ó�� �̸� �����صΰ� �Ѿ˹߻�)
//=============================================================
class triBullet : public gameNode
{
private:
	//�Ѿ� ����ü�� ���� ����, �ݺ���
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;
	vector<tagBullet> _vParticle;
	vector<tagBullet>::iterator _viParticle;
	vector<tagBullet> _vMagazine;
	vector<tagBullet>::iterator _viMagazine;



private:
	const char * _imageName;
	float _range;			//�Ѿ� ��Ÿ�
	int _bulletMax;			//�Ѿ� �ִ밹��

public:
	HRESULT init(const char * imageName, int bulletMax, float range);
	void release(void);
	void update(void);
	void render(void);

	//�Ѿ˹߻�
	void fire(float x, float y, float angle, float speed);
	//�Ѿ˹���
	void move();

	void collision();

	triBullet() {}
	~triBullet() {}
};

//=============================================================
//	## missileM1 ## (��źó�� �ѹ߾� �߻��ϸ鼭 �����ϰ� �ڵ�����)
//=============================================================
class missileM1 : public gameNode
{
private:
	//�Ѿ� ����ü�� ���� ����, �ݺ���
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;

private:
	float _range;			//�Ѿ� ��Ÿ�
	int _bulletMax;			//�Ѿ� �ִ밹��

public:
	HRESULT init(int bulletMax, float range);
	void release(void);
	void update(void);
	void render(void);

	//�Ѿ˹߻�
	void fire(float x, float y);
	//�Ѿ˹���
	void move();

	void removeMissileM1(int index);

	//�Ѿ˺��� ��������
	vector<tagBullet> getVBullet() { return _vBullet; }

	missileM1() {}
	~missileM1() {}
};





