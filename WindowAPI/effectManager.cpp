#include "stdafx.h"
#include "effectManager.h"
#include "effect.h"

HRESULT effectManager::init(void)
{
	this->addEffect("landDust", "fx_landDust", 0.3f, 5);
	this->addEffect("jumpDust1", "fx_jumpDust1", 0.3f, 5);
	this->addEffect("jumpDust2", "fx_jumpDust2", 0.3f, 5);
	this->addEffect("jumpDust3", "fx_jumpDust3", 0.3f, 5);
	this->addEffect("runDust0", "fx_runDust_right", 0.3f, 5);
	this->addEffect("runDust1", "fx_runDust_left", 0.3f, 5);
	this->addEffect("run1", "fx_run1", 0.3f, 5);
	this->addEffect("run2", "fx_run2", 0.3f, 5);
	this->addEffect("run3", "fx_run3", 0.3f, 5);
	this->addEffect("run4", "fx_run4", 0.3f, 5);
	this->addEffect("run5", "fx_run5", 0.3f, 5);
	this->addEffect("bulletPuff1", "fx_bulletPuff1", 0.3f, 5);
	this->addEffect("bulletPuff2", "fx_bulletPuff2", 0.3f, 5);
	this->addEffect("bulletPuff3", "fx_bulletPuff3", 0.3f, 5);
	this->addEffect("bulletPuff4", "fx_bulletPuff4", 0.3f, 5);
	this->addEffect("bulletPuff5", "fx_bulletPuff5", 0.3f, 5);
	this->addEffect("bulletFire0", "fx_bulletFire_right", 0.3f, 5);
	this->addEffect("bulletFire1", "fx_bulletFire_left", 0.3f, 5);
	this->addEffect("bulletFire2", "fx_bulletFire_diagonal_right", 0.3f, 5);
	this->addEffect("bulletFire3", "fx_bulletFire_diagonal_left", 0.3f, 5);
	this->addEffect("triBulletFire0", "fx_triBulletFire_right", 0.3f, 5);
	this->addEffect("triBulletFire1", "fx_triBulletFire_left", 0.3f, 5);
	this->addEffect("triBulletFire2", "fx_triBulletFire_diagonal_right", 0.3f, 5);
	this->addEffect("triBulletFire3", "fx_triBulletFire_diagonal_left", 0.3f, 5);
	this->addEffect("fullCharge_back", "fx_fullCharge_back", 0.3f, 5);
	this->addEffect("fullCharge_front", "fx_fullCharge_front", 0.3f, 5);

	return S_OK;
}

void effectManager::release(void)
{
	miEffect iter = _mEffect.begin();
	for (iter; iter != _mEffect.end(); ++iter)
	{
		viEffect vIter = iter->second.begin();
		for (int i = 0; i < iter->second.size(); i++)
		{
			iter->second[i]->release();
			SAFE_DELETE(iter->second[i]);
		}
	}
	_mEffect.clear();
}

void effectManager::update(void)
{
	miEffect mIter;
	mIter = _mEffect.begin();
	for (mIter; mIter != _mEffect.end(); ++mIter)
	{
		for (int i = 0; i < mIter->second.size(); i++)
		{
			mIter->second[i]->update();
		}
	}
}

void effectManager::render(void)
{
	miEffect mIter;
	mIter = _mEffect.begin();
	for (mIter; mIter != _mEffect.end(); ++mIter)
	{
		for (int i = 0; i < mIter->second.size(); i++)
		{
			mIter->second[i]->render();
		}
	}
}

void effectManager::addEffect(string effectName, const char * imageName, float effectFPS, int buffer, bool isFadeOut)
{
	image* img;
	vEffect vEffectBuffer;

	img = IMAGEMANAGER->findImage(imageName);
	for (int i = 0; i < buffer; i++)
	{
		vEffectBuffer.push_back(new effect);
		vEffectBuffer[i]->init(img, effectFPS, isFadeOut);
	}

	//이펙트버퍼 백터를 맵에 담기
	_mEffect.insert(make_pair(effectName, vEffectBuffer));
}

void effectManager::play(string effectName, int x, int y)
{
	miEffect mIter;

	for (mIter = _mEffect.begin(); mIter != _mEffect.end(); ++mIter)
	{
		if (!(mIter->first == effectName)) continue;

		//이펙트키와 일치하면 이펙트 실행
		for (int i = 0; i < mIter->second.size(); i++)
		{
			if (mIter->second[i]->getIsRunning()) continue;
			mIter->second[i]->startEffect(x, y);
			return;
		}
	}
}

//#include "stdafx.h"
//#include "effectManager.h"
//#include "effect.h"
//
//void effectManager::jumpDust(float x, float y)
//{
//	_jumpDust->setting(x, y);
//	_isJumpStart = true;
//}
//
//void effectManager::landDust(float x, float y)
//{
//	_landDust->setting(x, y);
//	_isLandStart = true;
//}
//
//void effectManager::runDust(float x, float y)
//{
//	_runDust->setting(x, y);
//	_isRunStart = true;
//}
//
//HRESULT effectManager::init(void)
//{
//	_jumpDust = new effect;
//	_jumpDust->init("fx_jumpDust", 5);
//	_landDust = new effect;
//	_landDust->init("fx_landDust", 5);
//	_runDust = new effect;
//	_runDust->init("fx_runDust", 5);
//	_isJumpStart = false;
//	_isLandStart = false;
//	_isRunStart = false;
//	return S_OK;
//}
//
//void effectManager::release(void)
//{
//	SAFE_DELETE(_jumpDust);
//	SAFE_DELETE(_landDust);
//	SAFE_DELETE(_runDust);
//}
//
//void effectManager::update(void)
//{
//	if (_isJumpStart)
//	{
//		_jumpDust->update();
//		if (_jumpDust->finish())
//		{
//			_isJumpStart = false;
//		}
//	}
//
//	if (_isLandStart)
//	{
//		_landDust->update();
//		if (_landDust->finish())
//		{
//			_isLandStart = false;
//		}
//	}
//
//	if (_isRunStart)
//	{
//		_runDust->update();
//		if (_runDust->finish())
//		{
//			_isRunStart = false;
//		}
//	}
//}
//
//void effectManager::render()
//{
//	if (_isJumpStart)
//	{
//		_jumpDust->render();
//	}
//
//	if (_isLandStart)
//	{
//		_landDust->render();
//	}
//
//	if (_isRunStart)
//	{
//		_runDust->render();
//	}
//}