/*
 * Copyright 2020 Google LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef THIRD_PARTY_AGENT_BASED_EPIDEMIC_SIM_CORE_TRANSMISSION_MODEL_H_
#define THIRD_PARTY_AGENT_BASED_EPIDEMIC_SIM_CORE_TRANSMISSION_MODEL_H_

#include "absl/types/span.h"
#include "agent_based_epidemic_sim/core/event.h"
#include "agent_based_epidemic_sim/core/visit.h"

namespace pandemic {

// Models transmission between hosts.
class TransmissionModel {
 public:
  // Computes the infection outcome given exposures.
  virtual HealthTransition GetInfectionOutcome(
      absl::Span<const Exposure* const> exposures) = 0;
  virtual ~TransmissionModel() = default;
};

}  // namespace pandemic

#endif  // THIRD_PARTY_AGENT_BASED_EPIDEMIC_SIM_CORE_TRANSMISSION_MODEL_H_
