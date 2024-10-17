% Facts

% Known car problems
problem(engine_failure).
problem(battery_issue).
problem(flat_tire).
problem(brake_issue).
problem(oil_leak).
problem(overheating).
problem(transmission_issue).

% Symptoms associated with problems
symptom(engine_failure, loud_noise).
symptom(engine_failure, engine_stalling).
symptom(battery_issue, headlights_dim).
symptom(battery_issue, car_wont_start).
symptom(flat_tire, tire_flatter).
symptom(flat_tire, car_pull_to_side).
symptom(brake_issue, squeaking_brakes).
symptom(brake_issue, brake_warning_light).
symptom(oil_leak, oil_spots).
symptom(oil_leak, engine_smoke).
symptom(overheating, temperature_warning_light).
symptom(overheating, steam_from_engine).
symptom(transmission_issue, slipping_gears).
symptom(transmission_issue, unusual_noises).

% Rules

% Diagnose the problem based on symptoms
diagnose(Problem) :- 
    symptom(Problem, Symptom), 
    ask_symptom(Symptom).

% Ask user about a symptom
ask_symptom(Symptom) :-
    format('Do you see the symptom: ~w? (yes/no) ', [Symptom]),
    read(Response),
    (Response == yes -> true; fail).

% Start the diagnosis process
start_diagnosis :-
    write('Welcome to the Car Problem Diagnosis Expert System.'), nl,
    (diagnose(Problem) ->
        format('The potential problem with your car is: ~w', [Problem])
    ;
        write('No problems detected based on the symptoms provided.')).

% To start the diagnosis, call:
% ?- start_diagnosis.
