

//Game hit mechanism
float calculateDistance(float*, float*);
BOOLEAN hitDetection(FnCharacter, FnCharacter, int skillCode);



float calculateDistance(float* a, float* b){
	float d1 = (a[0] - b[0])*(a[0] - b[0]);
	float d2 = (a[1] - b[1])*(a[1] - b[1]);
	float d3 = (a[2] - b[2])*(a[2] - b[2]);
	return  sqrt(d1+d2+d3);

}

/*////////////////////////////////////////////////////////////////////
	skillDistance == How far should the skill affect;	
	(A) : Actor Position
	(S) : Skill Position 
	
	(A)<-----skillDistance---->(S)
	
/////////////////////////////////////////////////////////////////////

	skillRadius == How wide should the skill affect;
	
		   ^
	(A)<---|---skillDistance---->(S)
	       |
		   v
	
	skillMinDistance == Minimal distance to hit;


/////////////////////////////////////////////////////////////////////

	(A)<--Safe Area--> <------skillDetection Area---->(S)
	   <------------skillDistance-------------------->


*/////////////////////////////////////////////////////////////////////


BOOLEAN hitDetection(FnCharacter actor, FnCharacter target,int skillCode){

	float actor_Pos[3] ;
	float target_Pos[3] ;
	float actor_fDir[3];
	float actor_uDir[3];
	float skill_Pos[3];
	actor.GetPosition(actor_Pos, TRUE);
	actor.GetDirection(actor_fDir, actor_uDir, TRUE);
	target.GetPosition(target_Pos, TRUE);

	//Normal Attack, Enum= 0
	float skillDistance = 0;
	float skillRadius = 0;
	float skillMinDistance = 0;
	if (skillCode == 0){
		//Normal Attack
		//Attacking  "==--->"  Linearly ,
		skillDistance = 230;	
		skillRadius = 30;
		skillMinDistance = 70;
		int i = 0;
		for (i = skillMinDistance; i <= skillDistance; i += 30){
			skill_Pos[0] = actor_Pos[0] + actor_fDir[0] * i;
			skill_Pos[1] = actor_Pos[1] + actor_fDir[1] * i;
			skill_Pos[2] = actor_Pos[2] + actor_fDir[2] * i;

			if (calculateDistance(skill_Pos, target_Pos)<skillRadius){
				return true;
			}
		}
	}


	return false;

}