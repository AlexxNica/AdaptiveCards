/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.12
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.microsoft.adaptivecards.objectmodel;

public class SeparatorConfig {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected SeparatorConfig(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(SeparatorConfig obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        AdaptiveCardObjectModelJNI.delete_SeparatorConfig(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public void setLineThickness(long value) {
    AdaptiveCardObjectModelJNI.SeparatorConfig_lineThickness_set(swigCPtr, this, value);
  }

  public long getLineThickness() {
    return AdaptiveCardObjectModelJNI.SeparatorConfig_lineThickness_get(swigCPtr, this);
  }

  public void setLineColor(String value) {
    AdaptiveCardObjectModelJNI.SeparatorConfig_lineColor_set(swigCPtr, this, value);
  }

  public String getLineColor() {
    return AdaptiveCardObjectModelJNI.SeparatorConfig_lineColor_get(swigCPtr, this);
  }

  public static SeparatorConfig Deserialize(SWIGTYPE_p_Json__Value json, SeparatorConfig defaultValue) {
    return new SeparatorConfig(AdaptiveCardObjectModelJNI.SeparatorConfig_Deserialize(SWIGTYPE_p_Json__Value.getCPtr(json), SeparatorConfig.getCPtr(defaultValue), defaultValue), true);
  }

  public SeparatorConfig() {
    this(AdaptiveCardObjectModelJNI.new_SeparatorConfig(), true);
  }

}
