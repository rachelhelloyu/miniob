//
// Created by emrick on 2021/10/31.
//

#ifndef MINIDB_EXECUTOR_BUILDER_H
#define MINIDB_EXECUTOR_BUILDER_H


#include <sql/parser/parse_defs.h>
#include <event/session_event.h>
#include <storage/default/default_handler.h>
#include "rc.h"
#include "executor.h"
#include "scan_executor.h"

class ExecutorBuilder {
public:
  ExecutorBuilder(const char *db, Query *sql, SessionEvent *session_event):
  db_(DefaultHandler::get_default().find_db(db)), sql_(sql), session_event_(session_event) {}

  Executor* build();

  Executor* build_select_executor();

  Executor* build_join_executor(Executor *executor);

  TupleSchema build_output_schema();


private:
  Db *db_;
  Query *sql_;
  SessionEvent *session_event_;
};



#endif //MINIDB_EXECUTOR_BUILDER_H