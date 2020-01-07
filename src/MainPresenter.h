#ifndef MainPresenter_h
#define MainPresenter_h

#include <Arduino.h>
#include <MHZ19.h>
#include <PubSubClient.h>

#include "MainView.h"

class MainPresenter {
    public:
        MainPresenter(MHZ19 &mhz19, MainView &mainView, PubSubClient &mqtt);
        void update();

    private:
        MHZ19 * const _mzh19;
        MainView * const _mainView;
        PubSubClient * const _mqtt;
};

#endif