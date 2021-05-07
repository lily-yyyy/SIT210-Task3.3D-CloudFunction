int led1=D7;

void myHandler(const char *event, const char *data); // forward declaration



void setup() {
    pinMode(led1, OUTPUT);
    Particle.subscribe("Deakin_RIOT_SIT210_Photon_Buddy", myHandler);

}

void loop() {
    //Since we are not at university and do not have another device,
    // we will publish instead of another device at with random wave
    delay(random(10000,20000));
    int randomnumber=random(-2,2);
    if(randomnumber<0) Particle.publish("Deakin_RIOT_SIT210_Photon_Buddy", "wave", PUBLIC);
    if(randomnumber>0 && randomnumber<=1) Particle.publish("Deakin_RIOT_SIT210_Photon_Buddy", "no_wave", PUBLIC);
    if(randomnumber>1) Particle.publish("Deakin_RIOT_SIT210_Photon_Buddy", "pat", PUBLIC);
    

}
void myHandler(const char *event, const char *data)
{
	/* Particle.subscribe handlers are void functions, which means they don't return anything.
	  They take two variables-- the name of your event, and any data that goes along with your event.
	  In this case, the event will be "buddy_unique_event_name" and the data will be "intact" or "broken"
	  Since the input here is a char, we can't do
		 data=="intact"
		or
		 data=="broken"
	  chars just don't play that way. Instead we're going to strcmp(), which compares two chars.
	  If they are the same, strcmp will return 0.
	 */

	if (strcmp(data,"wave")==0) {
		// if your buddy's beam is intact, then turn your board LED off
		digitalWrite(led1, HIGH);
		delay(1000);
		digitalWrite(led1, LOW);
		delay(1000);
		digitalWrite(led1, HIGH);
		delay(1000);
		digitalWrite(led1, LOW);
		delay(1000);
		digitalWrite(led1, HIGH);
		delay(1000);
		digitalWrite(led1, LOW);
		delay(1000);
	}
	else if (strcmp(data,"no_wave")==0) {
		// if your buddy's beam is broken, turn your board LED on
		digitalWrite(led1, LOW);
	}
	else if (strcmp(data,"pat")==0) {
	    
	    digitalWrite(led1, HIGH);
		delay(500);
		digitalWrite(led1, LOW);
		delay(500);
		digitalWrite(led1, HIGH);
		delay(500);
		digitalWrite(led1, LOW);
		delay(500);
		digitalWrite(led1, HIGH);
		delay(500);
		digitalWrite(led1, LOW);
		delay(500);
		
		
		
		digitalWrite(led1, HIGH);
		delay(500);
		digitalWrite(led1, LOW);
		delay(500);
		digitalWrite(led1, HIGH);
		delay(500);
		digitalWrite(led1, LOW);
		delay(500);
		digitalWrite(led1, HIGH);
		delay(500);
		digitalWrite(led1, LOW);
		delay(500);
		
		
		digitalWrite(led1, HIGH);
		delay(500);
		digitalWrite(led1, LOW);
		delay(500);
		digitalWrite(led1, HIGH);
		delay(500);
		digitalWrite(led1, LOW);
		delay(500);
		digitalWrite(led1, HIGH);
		delay(500);
		digitalWrite(led1, LOW);
		delay(500);
		
	}
	else
	{
	    // if the data is something else, don't do anything.
		// Really the data shouldn't be anything but those two listed above.
	}
}