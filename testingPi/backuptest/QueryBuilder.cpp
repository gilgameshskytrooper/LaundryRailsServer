#include <string>
#include <iostream>
#include "QueryBuilder.h"
using namespace std;

QueryBuilder::QueryBuilder() {
  cmd = "/usr/bin/curl";
  args = "--user laundry:3.1416Day";
  address = "http://devel.cs.stolaf.edu/laundry/A/write.exec";
  setup = cmd + " " + args + " " + address;
}
QueryBuilder::QueryBuilder(string state, string mach, string building, string flr) {
  cmd = "/usr/bin/curl";
  args = "--user laundry:3.1416Day";
  address = "http://devel.cs.stolaf.edu/laundry/A/write.exec";
  setup = cmd + " " + args + " " +address;
  append(state, mach, building, flr);
}


QueryBuilder::QueryBuilder(string mach, string building, string flr) {
  cmd = "/usr/bin/curl";
  args = "--user laundry:3.1416Day";
  address = "http://devel.cs.stolaf.edu/laundry/A/write.exec";
  setup = cmd + " " + args + " " +address;
}



string QueryBuilder::get_str() {
  return full;
}

void QueryBuilder::append(string state, string mach, string building, string flr) {
  machineState = state.substr(0, 2);
  machineType = mach.substr(0, 2);
  build = building.substr(0, 3);
  f = flr;
  full = setup + "\?sta=" + machineState + "\?mac=" + machineType + "\?bu=" + building + "\?f=" + flr;
}

void QueryBuilder::append(string mach, string building, string flr) {
  machineType = mach.substr(0, 2);
  build = building.substr(0, 3);
  f = flr;
}

void QueryBuilder::append(string state) {
  machineState = state.substr(0, 2);
  full = setup + "\?sta=" + machineState + "\?mac=" + machineType + "\?bu=" + build + "\?f=" + f;
}