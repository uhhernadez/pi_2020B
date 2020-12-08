using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class clienteOSC : MonoBehaviour
{
    public extOSC.OSCTransmitter transmitter;


    private void OnCollisionEnter(Collision collision)
    {
        var msg = new extOSC.OSCMessage("/unity/collision");
        msg.AddValue(extOSC.OSCValue.Int(200));
        transmitter.Send(msg);
        Debug.Log("Comenzó la collision");
    }


}
