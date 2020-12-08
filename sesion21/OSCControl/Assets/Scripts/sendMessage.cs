using UnityEngine;
using UnityEngine.UI;

public class sendMessage : MonoBehaviour
{
    #region Public Vars
    public string Address = "/android/message";
    public Text message;
    [Header("OSC Settings")]
    public extOSC.OSCTransmitter Transmitter;
    #endregion

    #region Unity Methods

    protected virtual void Start()
    {
        var message = new extOSC.OSCMessage(Address);
        message.AddValue(extOSC.OSCValue.String("Hello!"));
        Transmitter.Send(message);
    }

    public void OnSendMessage()
    { 
        var msg = new extOSC.OSCMessage(Address);
        Debug.Log("Sending this message"+message.text);
        msg.AddValue(extOSC.OSCValue.String(message.text));
        Transmitter.Send(msg); 
    }

    #endregion
}
