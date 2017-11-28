#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <random>
#include <thread>
#include <mutex>
#include <chrono>
#include <locale>
#include <time.h>
#include <math.h>
#include <getopt.h>
#include <signal.h>
#include <execinfo.h>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>

using namespace std;

#include "json.h"
#include "sqlite3.h"
#include "uWS/uWS.h"
#include "curl/curl.h"
#include "openssl/hmac.h"
#include "openssl/sha.h"
#include "openssl/md5.h"
#include "ncurses/ncurses.h"
#include "quickfix/NullStore.h"
#include "quickfix/Application.h"
#include "quickfix/SocketInitiator.h"
#include "quickfix/SessionSettings.h"
#include "quickfix/fix42/NewOrderSingle.h"
#include "quickfix/fix42/OrderCancelRequest.h"

using namespace nlohmann;

#include "km.h"
#include "fn.h"
#include "cf.h"
#include "ev.h"
#include "db.h"
#include "ui.h"
#include "qp.h"
#include "og.h"
#include "mg.h"
#include "pg.h"
#include "qe.h"
#include "gw.h"

int main(int argc, char** argv) {
  K::CF cf;
  K::EV ev;
  K::DB db;
  K::UI ui;
  K::QP qp;
  K::OG og;
  K::MG mg;
  K::PG pg;
  K::QE qe;
  K::GW gw;

  cf.main(argc, argv);
  cf.link(&ev,&db,&ui,&qp,&og,&mg,&pg,&qe,&gw);

  ev.wait();
  db.wait();
  ui.wait();
  qp.wait();
  og.wait();
  mg.wait();
  pg.wait();
  qe.wait();
  gw.wait();

  return EXIT_FAILURE;
}
