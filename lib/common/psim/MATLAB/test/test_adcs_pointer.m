state = adcs_initialize_pointer_state();
[state,magrod_moment_cmd,wheel_torque_cmd]=adcs_pointer(state,...
        zeros(3,1), zeros(3,1), ...
        [1;0;0],...
        [1;0;0],...
        [1;0;0],...
        [1;0;0],...
        zeros(3,1));
assert(isstruct(state),'state is not a struct')
assert(all(size(magrod_moment_cmd) == [3,1]),'magrod_moment_cmd is not size [3,1]')
assert(all(size(wheel_torque_cmd) == [3,1]),'wheel_torque_cmd is not size [3,1]')

[state,magrod_moment_cmd,wheel_torque_cmd]=adcs_pointer(state,...
        zeros(3,1), zeros(3,1), ...
        [1;0;0],...
        [1;0;0],...
        [0;1;0],...
        [0;-1;0],...
        zeros(3,1));
assert(isstruct(state),'state is not a struct')
assert(all(size(magrod_moment_cmd) == [3,1]),'magrod_moment_cmd is not size [3,1]')
assert(all(size(wheel_torque_cmd) == [3,1]),'wheel_torque_cmd is not size [3,1]')