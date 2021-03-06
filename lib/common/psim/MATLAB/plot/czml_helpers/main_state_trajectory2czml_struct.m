function [czml] = main_state_trajectory2czml_struct(main_state_trajectory,vector_names,color_names)
%main_state_trajectory2czml_struct Prepares main_state_trajectory for
% interactive animation using cesium viewer
%   
%   czml(a cell array of structs): each struct is a cesium packet
%   vector_names(string array):
%       vector names from the `get_truth` function to animate at each sat
%   color_names(string array):
%       color names for each vector, they are like the matlab plot colors codes

% Started by Nathan Zimmerberg on Feb 16, 2019
% Authors: Nathan Zimmerberg (nhz2@cornell.edu)
% Latest Revision: Feb 16, 2019
% Pathfinder for Autonomous Navigation
% Space Systems Design Studio
% Cornell University
global const
if nargin<=1
    vector_names= [];
    color_names= [];
end
names= string(fieldnames(main_state_trajectory{1}));
num_sats=length(names);
num_vectors= length(vector_names);
start_time= utl_time2datetime(main_state_trajectory{1}.(names(1)).dynamics.time, const.INITGPS_WN);
start_secs= main_state_trajectory{1}.(names(1)).dynamics.time;
duration_secs= main_state_trajectory{end}.(names(1)).dynamics.time-start_secs;
end_time= start_time+seconds(duration_secs);
interval_iso=string(start_time)+"/"+string(end_time);
tempfile=fopen("model_data_uri.txt",'rt');
model_uri= char(fread(tempfile,'*char')');
model_uri= string(model_uri(1:end-1));%remove end line
fclose(tempfile);
model_scale=10;
czml=cell(1,1+num_sats+num_sats*num_vectors*2);
czml{1}= struct('id','document',...
                        'name','My Document',...
                        'version','1.66',...
                        'clock',struct(...
                            'interval',interval_iso,...
                            'currentTime',string(start_time),...
                            'multiplier',1,...
                            'range','LOOP_STOP',...
                            'step','SYSTEM_CLOCK_MULTIPLIER')...
                        );
for i= 1:num_sats
    name= names(i);
    %start_secs
    posarrayecef=zeros(1,4*length(main_state_trajectory));
    quatarray=zeros(1,5*length(main_state_trajectory));
    for j= 0:(length(main_state_trajectory)-1)
        dynamics= main_state_trajectory{j+1}.(name).dynamics;
        time= get_truth('time',dynamics);
        pos_ecef= get_truth('position ecef',dynamics);
        posarrayecef(j*4+1)= time-start_secs;
        posarrayecef((j*4+2):(j*4+4))=pos_ecef(1:3);
        quatarray(j*5+1)= time-start_secs;
        quat_body_ecef=get_truth('quat body ecef',dynamics);
        quatarray((j*5+2):(j*5+5))= quat_body_ecef(1:4);
    end
    czml{i+1}= struct('id',name,...
                    'name',name,...
                    'availability',interval_iso,...
                    'model',struct(...
                        'gltf',model_uri,...
                        'scale',model_scale),...
                    'label',struct(...
                        "fillColor",struct(...
                            'rgba',[ 0, 255, 255, 255 ]),...
                        'font','11pt Lucida Console',...
                        'outlineColor',struct(...
                            'rgba', [ 0, 0, 0, 255 ]),...
                        "outlineWidth",2,...
                        "pixelOffset",struct(...
                            "cartesian2", [ 12, 0 ]),...
                        "show",true,...
                        "style", "FILL_AND_OUTLINE",...
                        "text",name,...
                        "verticalOrigin", "CENTER"),...
                     'position',struct(...
                        "interpolationAlgorithm", "LAGRANGE",...
                        "interpolationDegree", 5,...
                        "referenceFrame", "FIXED",...
                        "epoch",string(start_time),...
                        "cartesian",posarrayecef),...
                     "orientation",struct(...
                         "interpolationAlgorithm", "LINEAR",...
                         "interpolationDegree", 1,...
                         "epoch",string(start_time),...
                         "unitQuaternion",quatarray)...
                     );
	for k= 1:num_vectors %draw unit vectors on the objects
        vec_name= vector_names(k);
        [~,rgb,~] = colornames('MATLAB',char(color_names(k)));
        vecarrayecef=zeros(1,4*length(main_state_trajectory));
        for j= 0:(length(main_state_trajectory)-1)
            dynamics= main_state_trajectory{j+1}.(name).dynamics;
            time= get_truth('time',dynamics);
            scale= 1;
            pos_ecef= get_truth('position ecef',dynamics);
            vect_ecef= get_truth(vec_name+" ecef",dynamics);
            vect_ecef=vect_ecef/norm(vect_ecef);
            vecarrayecef(j*4+1)= time-start_secs;
            vecarrayecef((j*4+2):(j*4+4))=vect_ecef(1:3)*scale+pos_ecef;
        end
        czml{num_sats+1+(k*2-1)+(i-1)*num_vectors*2}= struct('id',name+"/"+vec_name+"/endpoint",...
                'parent',name,...
                'name',name+"/"+vec_name+"/endpoint",...
                'availability',interval_iso,...
                'label',struct(...
                    "fillColor",struct(...
                        'rgbaf',[ rgb, 1 ]),...
                    'font','11pt Lucida Console',...
                    'outlineColor',struct(...
                        'rgba', [ 0, 0, 0, 255 ]),...
                    "outlineWidth",2,...
                    "pixelOffset",struct(...
                        "cartesian2", [ 12, 0 ]),...
                    "show",true,...
                    "style", "FILL_AND_OUTLINE",...
                    "text",vec_name,...
                    "verticalOrigin", "CENTER"),...
                 'position',struct(...
                        "interpolationAlgorithm", "LAGRANGE",...
                        "interpolationDegree", 5,...
                        "referenceFrame", "FIXED",...
                        "epoch",string(start_time),...
                        "cartesian",vecarrayecef)...
                 );
        czml{num_sats+1+k*2+(i-1)*num_vectors*2}= struct('id',name+"/"+vec_name,...
                'parent',name,...
                'name',name+"/"+vec_name,...
                'availability',interval_iso,...
                'polyline',struct(...
                    'positions', struct(...
                        'references',[name+"#position",name+"/"+vec_name+"/endpoint"+"#position"]),...
                    'arcType','NONE',...
                    'material',struct(...
                        "polylineArrow",struct(...
                            'color',struct(...
                                'rgbaf',[ rgb, 1 ]))),...
                    "width",10),...
                 'position',struct(...
                     "reference",name+"#position")...
                 );
    end
end