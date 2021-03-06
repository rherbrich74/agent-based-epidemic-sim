// Copyright 2020 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "absl/flags/flag.h"
#include "absl/flags/parse.h"
#include "agent_based_epidemic_sim/applications/home_work/config.pb.h"
#include "agent_based_epidemic_sim/applications/home_work/simulation.h"
#include "agent_based_epidemic_sim/core/parse_text_proto.h"
#include "agent_based_epidemic_sim/port/file_utils.h"
#include "agent_based_epidemic_sim/port/logging.h"

ABSL_FLAG(std::string, simulation_config_pbtxt_path, "",
          "Path to SimulationConfig pbtxt file.");
ABSL_FLAG(int, num_workers, 1, "The number of thread workers to use.");
ABSL_FLAG(std::string, output_file_path, "", "The output file path.");

namespace pandemic {

int Main(int argc, char** argv) {
  std::string contents;
  CHECK_EQ(absl::OkStatus(),
           file::GetContents(absl::GetFlag(FLAGS_simulation_config_pbtxt_path),
                             &contents));
  const HomeWorkSimulationConfig config =
      ParseTextProtoOrDie<HomeWorkSimulationConfig>(contents);
  RunSimulation(absl::GetFlag(FLAGS_output_file_path), config,
                absl::GetFlag(FLAGS_num_workers));
  return 0;
}

}  // namespace pandemic

int main(int argc, char** argv) {
  google::InitGoogleLogging(argv[0]);
  absl::ParseCommandLine(argc, argv);
  return pandemic::Main(argc, argv);
}
