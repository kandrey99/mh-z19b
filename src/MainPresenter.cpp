#include "MainPresenter.h"

MainPresenter::MainPresenter(MHZ19 &mhz19, MainView &mainView, PubSubClient &mqtt) :
    _mzh19(&mhz19), _mainView(&mainView), _mqtt(&mqtt)
{    
}

void MainPresenter::update()
{
    int co2 = _mzh19->getCO2();
    _mainView->setCO2(co2);
    _mqtt->publish("mh-z19b/co2", ((String)co2).c_str());

    int t = _mzh19->getTemperature();
    _mainView->setTemperature(t);
    _mqtt->publish("mh-z19b/temperature", ((String)t).c_str());

    // float co2Raw = _mzh19->getCO2Raw();
    // _mainView->setCO2Raw(co2Raw);

    // int range = _mzh19->getRange();
    // _mainView->setRange(range);

    // int bCo2 = _mzh19->getBackgroundCO2();
    // _mainView->setBackgroundCO2(bCo2);

    // int accuracy = _mzh19->getAccuracy();
    // _mainView->setAccuracy(accuracy);
}