// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE

import * as Core from "@aws-amplify/core";

function make(prim, prim$1, prim$2) {
  return {
          event: prim,
          data: prim$1,
          message: prim$2
        };
}

var HubPayload = {
  make: make
};

function listen(string, callback) {
  Core.Hub.listen(string, callback);
  return /* () */0;
}

function remove(string, callback) {
  Core.Hub.remove(string, callback);
  return /* () */0;
}

export {
  HubPayload ,
  listen ,
  remove ,
  
}
/* @aws-amplify/core Not a pure module */
