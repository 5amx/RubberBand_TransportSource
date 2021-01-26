/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <rubberband/RubberBandStretcher.h>
#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/**
*/
class AudioPlayerPluginAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    AudioPlayerPluginAudioProcessor();
    ~AudioPlayerPluginAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    AudioProcessorValueTreeState params;
    void openFile();
    void loadFile(File& file);

private:
    AudioFormatManager audioFormatManager;
    File audioFile;
    
    AudioTransportSource transportSource;
    std::unique_ptr<AudioFormatReaderSource> audioFileSource;
    
    //RUBBERBAND
    AudioBuffer<float> mTempBuffer;
    std::unique_ptr<RubberBand::RubberBandStretcher> rb;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioPlayerPluginAudioProcessor)
};
