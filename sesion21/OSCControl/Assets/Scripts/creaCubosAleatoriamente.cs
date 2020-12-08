using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class creaCubosAleatoriamente : MonoBehaviour
{
    public GameObject [] prefab;

    void Start()
    {
        for(int k = 0; k < prefab.Length;k++) { 
            Vector3 position = new Vector3(Random.Range(-2.0f, 2.0f), Random.Range(0.5f, 10.0f), Random.Range(-2.0f, 2.0f));
            prefab[k].transform.position = position;   
        }
    }

}
